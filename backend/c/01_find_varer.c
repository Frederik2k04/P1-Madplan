#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
    sqlite3 *db = NULL;
    sqlite3_stmt *stmt = NULL;

    if (argc != 3) {
        fprintf(stderr, "Brug: %s databasefil soegeord\n", argv[0]);
        return 1;
    }

    int result = sqlite3_open_v2(argv[1], &db, SQLITE_OPEN_READONLY, NULL);
    if (result != SQLITE_OK) {
        fprintf(stderr, "Kan ikke åbne databasen: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    const char *sql =
        "SELECT id, navn, pakke_maengde, pakke_enhed, pris_oere "
        "FROM v_madplan "
        "WHERE kaede_id = 'rema1000' AND er_estimat = 0 "
        "AND navn_soeg LIKE '%' || ?1 || '%' "
        "ORDER BY pris_oere, id LIMIT 20;";

    result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
        fprintf(stderr, "Fejl i opslaget: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    result = sqlite3_bind_text(stmt, 1, argv[2], -1, SQLITE_TRANSIENT);
    if (result != SQLITE_OK) {
        fprintf(stderr, "Kan ikke indsætte søgeordet: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }

    int count = 0;
    while ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        const char *name = (const char *)sqlite3_column_text(stmt, 1);
        const char *unit = (const char *)sqlite3_column_text(stmt, 3);
        if (name == NULL || unit == NULL) {
            fprintf(stderr, "En vare mangler navn eller enhed.\n");
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }

        long long price = sqlite3_column_int64(stmt, 4);
        printf("ID %d | %s | %g %s | %lld,%02lld kr.\n",
               sqlite3_column_int(stmt, 0), name,
               sqlite3_column_double(stmt, 2), unit,
               price / 100, price % 100);
        count++;
    }

    if (result != SQLITE_DONE) {
        fprintf(stderr, "Fejl under læsning: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return 1;
    }
    if (count == 0) {
        printf("Ingen varer fundet i dette udvalg.\n");
    }

    int finalize_result = sqlite3_finalize(stmt);
    int close_result = sqlite3_close(db);
    if (finalize_result != SQLITE_OK || close_result != SQLITE_OK) {
        fprintf(stderr, "Fejl ved afslutning af databaseopslaget.\n");
        return 1;
    }
    return 0;
}
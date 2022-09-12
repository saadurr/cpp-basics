#include <iostream>
#include <sqlite3.h>
#include <sqlcpp.h>

constexpr const char* db_file = DB_PATH "/scratch.db";

int main()
{
	std::cout << "sqlite3 version is: " << sqlite3_libversion() << std::endl;
	std::cout << "sqlite3 source ID is: " << sqlite3_sourceid() << std::endl;

    sqlite3* db = nullptr;
    sqlite3_stmt* stmt = nullptr;

    printf("sqlite3 version: %s\n", sqlite3_libversion());
    printf("db file: %s\n", db_file);

    // open the database
    int rc = sqlite3_open(db_file, &db);
    if (rc == SQLITE_OK) 
    {
        puts("database open");
    }
    else 
    {
        puts(sqlite3_errstr(rc));
        exit(1);
    }

    // prepare a statement
    sqlite3_prepare_v2(db, "SELECT * FROM customer", -1, &stmt, nullptr);

    // list column names
    int col_count = sqlite3_column_count(stmt);
    for (int i = 0; i < col_count; ++i) 
    {
        printf("%s", sqlite3_column_name(stmt, i));
        if (i < col_count - 1) printf(", ");
    }
    puts("");

    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        for (int i = 0; i < col_count; ++i) 
        {
            printf("%s", sqlite3_column_text(stmt, i));
            if (i < col_count - 1) printf(", ");
        }
        puts("");
    }

    puts("finalize statement");
    sqlite3_finalize(stmt);
    puts("close db");
    sqlite3_close(db);
    puts("done");


	//std::cin.get();
	return 0;
}
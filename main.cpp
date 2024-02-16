#include <iostream>
#include <sqlite3.h>
#include "Data_Calls.h"
int main() {
    sqlite3 *db;
    int rc = sqlite3_open("STUDENT_MAJOR_SHEETS.db ", &db); // Change "example.db" to your actual database file

    if (rc == SQLITE_OK) {
        std::cout << "Database connection established." << std::endl;

        // Call the function to print rows from the COURSE table
        printCourseRows(db);

        sqlite3_close(db);
        std::cout << "Database connection closed." << std::endl;
    } else {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
    }

    return 0;
}

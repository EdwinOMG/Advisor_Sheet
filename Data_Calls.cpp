//
// Created by Edwin Morales Jr on 2/14/24.
//

#include "Data_Calls.h"

void printCourseRows(sqlite3 *db) {
    const char *sql = "SELECT * FROM Course;";
    sqlite3_stmt *stmt;


    // Prepare the SQL statement
    int prepareResult = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (prepareResult == SQLITE_OK) {
        // Step through the result set
        int stepResult;
        while ((stepResult = sqlite3_step(stmt)) == SQLITE_ROW) {
            // Access columns using sqlite3_column_XXX functions
            int courseId = sqlite3_column_int(stmt, 0);  // Assuming Course_ID is the first column
            const char *courseName = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));  // Assuming Course_Name is the second column
            int courseCredits = sqlite3_column_int(stmt, 2);  // Assuming Course_Credits is the third column
            int majorId = sqlite3_column_int(stmt, 3);  // Assuming Major_ID is the fourth column

            // Process the retrieved data (print it in this example)
            std::cout << "Course ID: " << courseId << ", Name: " << courseName
                      << ", Credits: " << courseCredits << ", Major ID: " << majorId << std::endl;
        }

        // Check for errors in the result set iteration
        if (stepResult != SQLITE_DONE) {
            std::cerr << "Error iterating over result set: " << sqlite3_errmsg(db) << std::endl;
        }

        // Finalize the statement to release resources
        sqlite3_finalize(stmt);
    } else {
        // Handle query preparation error
        std::cerr << "Error preparing SQL query: " << sqlite3_errmsg(db) << std::endl;
    }
}

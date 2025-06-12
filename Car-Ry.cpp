#include <sqlite3.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

static int createDB(const char *s);
static int createTable(const char *s);
static int deleteData(const char *s);
static int insertData(const char *s);
static int IncrementData(const char *s);
// static int IncrementDeletionData(const char* s, int inc);
static int updateNameData(const char *s);
static int updateLNameData(const char *s);
static int updateAgeData(const char *s);
static int updateCarData(const char *s);
static int updateAmountData(const char *s);
static int selectData(const char *s);
static int deleteentry(const char *s);
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main()
{
    const char *dir = R"(C:\Users\YashiKrishna\Desktop\database sql\CARS.db)";
    int option, x;
    createDB(dir);
    createTable(dir);
jump:
    cout << endl;
    cout << "Welcome To CAR-RY!! \n";
    cout << "What would you like to do? \n";
    cout << "1. See All Entries \n";
    cout << "2. Add An Entry \n";
    cout << "3. Delete An Entry \n";
    cout << "4. Update Data \n";
    cout << "5. Delete ALL ENTRIES \n";
    cout << "6. EXIT PROGRAM \n";
    cout << "Enter your choice!\n";
    cin >> option;
    cout << endl;
    switch (option)
    {
    case 1:
        IncrementData(dir);
        selectData(dir);
        goto jump;
        break;
    case 2:
        IncrementData(dir);
        insertData(dir);
        goto jump;
        break;
    case 3:
        deleteentry(dir);
        // IncrementData(dir);
        goto jump;
        break;
    case 4:
    hop:
        cout << "Which entry would you like to update\n";
        cout << "1. NAME\n";
        cout << "2. LNAME\n";
        cout << "3. AGE\n";
        cout << "4. CAR\n";
        cout << "5. AMOUNT\n";
        cout << "6. GO BACK \n";
        cin >> x;
        switch (x)
        {
        case 1:
            updateNameData(dir);
            goto hop;
            break;
        case 2:
            updateLNameData(dir);
            goto hop;
            break;
        case 3:
            updateAgeData(dir);
            goto hop;
            break;
        case 4:
            updateCarData(dir);
            goto hop;
            break;
        case 5:
            updateAmountData(dir);
            goto hop;
            break;
        case 6:
            goto jump;
            break;
        }
    case 5:
        deleteData(dir);
        IncrementData(dir);
        goto jump;
        break;
    case 6:
        int i, j, k, l, m, n, s, space, spa, sp;
        for (i = 1; i <= 5; i++)
        {
            // for T
            for (j = 1; j <= 5; j++)
            {
                if (i > 1 && (j == 2 || j == 1))
                {
                    printf("  ");
                }
                if (i == 1 || j == 3)
                {
                    printf("* ");
                }
                if (i > 1 && (j == 4 || j == 5))
                {
                    printf("  ");
                }
            }
            printf(" ");
            // for H
            for (k = 1; k <= 5; k++)
            {
                if (k == 5 || i == 3 || k == 1)
                {
                    printf("* ");
                }
                else
                {
                    printf("  ");
                }
            }

            // for A
            for (space = 5; space >= i; space--)
            {
                printf(" ");
            }
            for (l = 1; l <= 5; l++)
            {
                if (l == 1)
                {
                    printf("*");
                }
                if (i == 2 && l == 2)
                {
                    printf(" *");
                }
                if (i == 3 && l == 2)
                {
                    printf(" *");
                }
                if (i > 3 && l < 3)
                {
                    for (spa = 3; spa <= i; spa++)
                    {
                        printf(" ");
                    }
                }
                if (i > 2 && l == 2)
                {
                    printf(" *");
                }
            }
            for (space = 5; space >= i; space--)
            {
                printf(" ");
            }
            printf(" ");
            // for N
            for (m = 1; m <= 5; m++)
            {
                if (m == 1)
                {
                    printf("* ");
                }
                if (m == 5)
                {
                    printf("*  ");
                }
                if (m != i && m != 5 && m != 1)
                {
                    printf("  ");
                }
                if (m == i && m != 1 && m != 5)
                {
                    printf("* ");
                }
            }
            // for K
            for (n = 1; n <= 5; n++)
            {
                if (n == 1)
                {
                    printf("* ");
                }
                if ((i == 1 || i == 2) && n == 2)
                {
                    for (sp = 2; sp >= i; sp--)
                    {
                        printf(" ");
                    }
                    printf("*");
                }
                if (i == 3 && n == 2)
                {
                    printf("*");
                }
                if ((i == 4 || i == 5) && n == 2)
                {
                    for (sp = 4; sp <= i; sp++)
                    {
                        printf(" ");
                    }
                    printf("*");
                }
            }
            if (i < 4)
            {
                for (sp = 1; sp <= i; sp++)
                {
                    printf(" ");
                }
            }
            if (i > 3)
            {
                for (sp = 5; sp >= i; sp--)
                {
                    printf(" ");
                }
            }
            printf(" ");
            // for S
            for (s = 1; s <= 5; s++)
            {
                if (i != 2 && i != 4)
                {
                    printf("* ");
                }
                if (i == 2 && s == 1)
                {
                    printf("* ");
                }
                if (i == 4 && s == 1)
                {
                    printf("        *");
                }
            }
            printf("\n");
        }
        return 0;
        break;
    }
    // deleteData(dir); // use prior to insert
    // IncrementData(dir);
    // insertData(dir); // uncomment the deleteData above to avoid duplicates
    // insertData(dir);
    // updateData(dir);
    selectData(dir);

    return 0;
}

static int createDB(const char *s)
{
    sqlite3 *DB;

    int exit = 0;
    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);

    return 0;
}

static int createTable(const char *s)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS RENTAL("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME      TEXT NOT NULL, "
                 "LNAME     TEXT NOT NULL, "
                 "AGE       INT  NOT NULL, "
                 "CAR   CHAR(10), "
                 "AMOUNT     INT);";

    try
    {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error in createTable function." << endl;
            sqlite3_free(messageError);
        }
        else
            cout << "Table created Successfully" << endl;
        sqlite3_close(DB);
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }

    return 0;
}
static int insertData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    string fname, lname, carname;
    int age = 0, amount = 0;
    cout << "Enter Customer's first name : ";
    cin >> fname;
    cout << "Enter Customer's last name : ";
    cin >> lname;
    cout << "Enter the Age : ";
    cin >> age;
    cout << "Enter Car name : ";
    cin >> carname;
    cout << "Enter Rent Amount : ";
    cin >> amount;
    string sql("INSERT INTO RENTAL (NAME, LNAME, AGE, CAR, AMOUNT) VALUES('" + string(fname) + "','" + string(lname) + "'," + std::to_string(age) + ",'" + string(carname) + "'," + std::to_string(amount) + "); ");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in insertData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records inserted Successfully!" << endl;

    return 0;
}
static int deleteentry(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int num;
    cout << "Enter ID number to delete : ";
    cin >> num;
    string sql = "DELETE FROM RENTAL where ID= " + std::to_string(num) + ";";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in deleteID function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record for ID " << num << " deleted Successfully!" << endl;
    return 0;
}

static int IncrementData(const char *s)
{
    sqlite3 *DB;
    char *messageError;

    string sql("UPDATE `sqlite_sequence` SET `seq` = 0 WHERE `name` = 'RENTAL';");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << endl;

    return 0;
}

static int updateNameData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int y;
    string naam;
    cout << "enter ID to update : ";
    cin >> y;
    cout << "enter new name : ";
    cin >> naam;

    string sql("UPDATE RENTAL SET NAME = '" + string(naam) + "' WHERE ID = " + std::to_string(y) + ";");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record updated Successfully!" << endl;

    return 0;
}

static int updateLNameData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int y;
    string lnaam;
    cout << "enter ID to update : ";
    cin >> y;
    cout << "enter new last name : ";
    cin >> lnaam;

    string sql("UPDATE RENTAL SET LNAME = '" + string(lnaam) + "' WHERE ID = " + std::to_string(y) + ";");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record updated Successfully!" << endl;

    return 0;
}

static int updateAgeData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int y;
    int age;
    cout << "enter ID to update : ";
    cin >> y;
    cout << "enter new age : ";
    cin >> age;

    string sql("UPDATE RENTAL SET AGE = " + std::to_string(age) + " WHERE ID = " + std::to_string(y) + ";");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record updated Successfully!" << endl;

    return 0;
}

static int updateCarData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int y;
    string car;
    cout << "enter ID to update : ";
    cin >> y;
    cout << "enter new car name : ";
    cin >> car;

    string sql("UPDATE RENTAL SET LNAME = '" + string(car) + "' WHERE ID = " + std::to_string(y) + ";");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record updated Successfully!" << endl;

    return 0;
}

static int updateAmountData(const char *s)
{
    sqlite3 *DB;
    char *messageError;
    int y;
    int amount;
    cout << "enter ID to update : ";
    cin >> y;
    cout << "enter new amount : ";
    cin >> amount;

    string sql("UPDATE RENTAL SET AGE = " + std::to_string(amount) + " WHERE ID = " + std::to_string(y) + ";");

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in updateData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Record updated Successfully!" << endl;

    return 0;
}

static int deleteData(const char *s)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "DELETE FROM RENTAL;";
    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error in deleteData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records deleted Successfully!" << endl;

    return 0;
}

static int selectData(const char *s)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT * FROM RENTAL;";

    int exit = sqlite3_open(s, &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error in selectData function." << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records selected Successfully!" << endl;

    return 0;
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        // column name and value
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    cout << endl;

    return 0;
}

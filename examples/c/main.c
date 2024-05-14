#include <libpq-fe.h>

int main(int argc, char **argv)
{
    PGconn *conn = PQconnectdb("dbname=postgres password=postgres user=postgres host=localhost port=5432");
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "connection to database failed: %s", PQerrorMessage(conn));

        PQfinish(conn);
        return 1;
    }

    printf("connected to database\n");
    PQfinish(conn);

    return 0;
}

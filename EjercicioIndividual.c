#include <stdio.h>
#include <my_global.h>
#include <string.h>
#include <mysql.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	MYSQL *conn;
	int err;
	
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	
	conn = mysql_init(NULL);
	if (conn == NULL) {
		printf ("Error de conexión: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	conn = mysql_real_connect (conn, "localhost", "root", "mysql", "videojuego",0, NULL, 0);
	if (conn == NULL) {
		printf ("Error al inicializar la conexión: %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1)
	}
	
	char username[40];
	printf("Escribe el username\n");
	scanf("%s", username);
	
	char consulta[80];
	strcpy(consulta, "SELECT PARTIDA.DURACION FROM JUGADOR, PARTIDA WHERE PARTIDA.JUGADOR1 = '");
	strcat(consulta, username);
	strcat(consulta, "' OR PARTIDA.JUGADOR2 = '");
	stract(consulta, username);
	
	err = mysql_query (conn, consulta);
	if (err != 0) {
		printf ("Error al consultar datos de la base %u %s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
	}
	
	resultado = mysql_store_result(conn);
	row = mysql_fetch_row(resultado);
	
	if (row == NULL) 
		printf ("No se han obtenido datos en la consulta"\n);
	else
		double media = 0;
		int partidas = 0;
		while (row != NULL) {
			media = row[0] + media;
			partidas = partidas + 1;
			row = mysql_fetch_row (resultado);
		}
		printf("Duración media %d", media);
	
	mysql_close(conn);
	exit(0);
}


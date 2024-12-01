//Semestral Principio de Programacion 2022;
//Rodolfo Campos 8-905-2179, Adriana Achurra 8-990-123;

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<math.h>

//Constantes Globales				Puede cambiar el tamaño de las mesas y computadoras.
#define MESAS 3						//Lo hicimos escalable a futuro cambiando las constantes a variables para una funcion de cambiar tamaño
#define COMPUTADORAS 4
#define PERSONAS 20

//Declaracion de Funciones
int ImprimirBanner();
int ImprimirLaboratorio(int mesas, int computadoras, int laboratorio[mesas][computadoras]);                       //Funcion para imprimir Las mesas y computadoras
int ValidarNumero(int n);                                                                                         //Funcion para validar numero de entrada
int VerificarCedula();                                                                                            //Funcion para verficar acceso con cedula
int Reservar(int personas, int mesas, int computadoras, int laboratorio[mesas][computadoras], int registro[personas][(mesas*computadoras)+1]);  //Funcion para reservar computadora
int Cancelar(int mesas, int computadoras, int laboratorio[mesas][computadoras]);                                  //Funcion para cancelar reserva de computadora
int ImprimirRegistro(int personas, int mesas, int computadoras, int registro[personas][(mesas*computadoras)+1]);  //Funcion para imprimir el registro de reservas
int ImprimirListado();                                                                                            //Funcion para imprimir listado de personas con acceso a reservass


//Listado de Acceso
char todasLasCedulas[PERSONAS][15]=
{
	"8-756-2131",
	"8-905-2179",
	"8-990-123",
	"8-996-1219",
	"20-5-7353",
	"8-1002-1756",
	"8-1095-516",
	"2-752-1519",
	"8-1012-1297",
	"8-1010-1697",
	"8-1004-172",
	"8-973-1067",
	"3-752-865",
	"8-996-518",
	"8-1006-298",
	"8-996-1793",
	"8-1001-2089",
	"8-1006-1899",
	"3-753-1582",
	"8-1001-1046"
};
	
char todosLosNombres[PERSONAS][15]=
{
	"Kexy",
	"Rodolfo",
	"Adriana",
	"Victor",
	"Sebastian",
	"Alexander",
	"Went",
	"Arantxa",
	"Paola",
	"Stefany",
	"Jeremiah",
	"Pedro",
	"Rodrigo",
	"Eynar",
	"Angel",
	"Mariangel",
	"Allan",
	"Denisse",
	"Jessica",
	"Moises"
};

char todosLosApellidos[PERSONAS][15]=
{
	"Rodriguez",
	"Campos",
	"Achurra",
	"Arrocha",
	"Olivera",
	"Camargo",
	"Chung",
	"Coronado",
	"Quiñones",
	"Gonzalez",
	"Kurmaty",
	"Lucero",
	"Molinar",
	"Morales",
	"Medina",
	"Santos",
	"Vega",
	"Zepeda",
	"Wong",
	"Delgado"
};

int main()
{
	//Declaracion de Variables
	int rodolfo, adriana, seleccion, mesa, computadora, laboratorio[MESAS][COMPUTADORAS], registro[PERSONAS][(MESAS*COMPUTADORAS)+1];
	
	//Valorando ArregloS
	for (rodolfo=0; rodolfo<MESAS; rodolfo++)
	{
		for (adriana=0; adriana<COMPUTADORAS; adriana++)
		{
			laboratorio[rodolfo][adriana] = 0;
		}
	}
	
	for (rodolfo=0; rodolfo<PERSONAS; rodolfo++)
	{
		for (adriana=0; adriana<(MESAS*COMPUTADORAS)+1; adriana++)
		{
			registro[rodolfo][adriana] = 0;
		}
	}
	
	//Ciclo Principal
	do
	{
		system("cls");
		printf("\n");
		ImprimirBanner();
		printf(" BIENVENIDO AL LABORATORIO DE COMPUTO!\n\n");
		printf(" Seleccione una de las siguientes opciones para continuar:\n\n");
		printf("  1. Ver los puestos de las computadoras ocupadas y disponibles.\n");
		printf("  2. Reservar una computadora.\n");
		printf("  3. Salir del laboratorio.\n");
		printf("  4. Registro del uso del laboratorio.\n");
		printf("  5. Ver el listado de los estudiantes autorizado para usar el laboratorio.\n");
		printf("  6. Salir del sistema.\n\n");
		printf(" Seleccion: ");
		scanf("%d", &seleccion);
		switch(seleccion)
		{
			case 1:
				system("cls");
				ImprimirLaboratorio(MESAS, COMPUTADORAS, laboratorio);
				printf("Presione cualquier tecla para regresar\n");
				system("PAUSE");
				break;
			case 2:
				Reservar(PERSONAS, MESAS, COMPUTADORAS, laboratorio, registro);
				system("PAUSE");
				break;
			case 3:
				Cancelar(MESAS, COMPUTADORAS, laboratorio);
				system("PAUSE");
				break;
			case 4:
				ImprimirRegistro(PERSONAS, MESAS, COMPUTADORAS, registro);
				system("PAUSE");
				break;
			case 5:
				ImprimirListado();
					system("PAUSE");
				break;
			case 6:
				ImprimirFin();
				break;
			default:
				printf("\n\033[31m >> inserte un numero valido <<\033[0m\n");
				system("PAUSE");
		}
	}while (seleccion!=6);
	return 0;
}

int ImprimirBanner()
{
	printf(" \033[90m'\033[33m##\033[90m::::::::::'\033[33m###\033[90m::::'\033[33m########\033[90m:::'\033[33m#######\033[90m::'\033[33m########\033[90m:::::'\033[33m###\033[90m::::'\033[33m########\033[90m::'\033[33m#######\033[90m::'\033[33m########\033[90m::'\033[33m####\033[90m::'\033[33m#######\033[90m::\n");
	printf(" \033[90m \033[33m##\033[90m:::::::::'\033[33m##\033[90m \033[33m##\033[90m::: \033[33m##\033[90m.... \033[33m##\033[90m:'\033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m:::'\033[33m##\033[90m \033[33m##\033[90m:::... \033[33m##\033[90m..::'\033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m:. \033[33m##\033[90m::'\033[33m##\033[90m.... \033[33m##\033[90m:\n");
	printf(" \033[90m \033[33m##\033[90m::::::::'\033[33m##\033[90m:. \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m::'\033[33m##\033[90m:. \033[33m##\033[90m::::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m:: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	printf(" \033[90m \033[33m##\033[90m:::::::'\033[33m##\033[90m:::. \033[33m##\033[90m: \033[33m########\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::'\033[33m##\033[90m:::. \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	printf(" \033[90m \033[33m##\033[90m::::::: \033[33m#########\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m.. \033[33m##\033[90m::: \033[33m#########\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m.. \033[33m##\033[90m:::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	printf(" \033[90m \033[33m##\033[90m::::::: \033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m::. \033[33m##\033[90m:: \033[33m##\033[90m.... \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m::. \033[33m##\033[90m::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	printf(" \033[90m \033[33m########\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::. \033[33m#######\033[90m:: \033[33m##\033[90m:::. \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m::::. \033[33m#######\033[90m:: \033[33m##\033[90m:::. \033[33m##\033[90m:'\033[33m####\033[90m:. \033[33m#######\033[90m::\n");
	printf(" \033[90m........::..:::::..::........::::.......:::..:::::..::..:::::..:::::..::::::.......:::..:::::..::....:::.......:::\033[0m\n\n");
}

int ImprimirLaboratorio(int mesas, int computadoras, int laboratorio[mesas][computadoras])  //Funcion para imprimir Las mesas y computadoras
{
	//Declaracion de Variables
	int m, c;
	
	//Bloque de Instrucciones
	printf("\n\033[33m                    TABLA DE PUESTOS DE COMPUTADORAS DISPINIBLES.\033[0m\n\n");
	
	for (m=0; m<mesas; m++)
	{
		printf("\033[33m Mesa %d\033[0m:  \n ", m+1);
		for (c=0; c<computadoras; c++)
		{
			printf("_____________________");
		}
		printf("_\n");
		printf("| ");
		for (c=0; c<computadoras; c++)
		{
			printf("____________________ ");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("  ___________   __  |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |           | |==| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |     %d     | |--| |", c+1);
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |___________| |  | |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("      | |      |--| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("  ===========  |__| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			if(laboratorio[m][c]==0)
			{	
				printf("  \033[32m Disponible \033[0m      |");
			}
			else if(laboratorio[m][c]>0)
			{
				printf(" \033[31m No Disponible \033[0m    |");
			}
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("____________________|");
		}
		printf("|\n|_");
		for (c=0; c<computadoras; c++)
		{
			printf("_____________________");
		}
		printf("|\n\n");
	}
}

int ValidarNumero(int n)  //Funcion para validar numero de entrada
{
	//Declaracion de Variable
	int i;
	
	//Bloque de Instrucciones
	do
	{	
		scanf("%d", &i);
		if (i<1 || i>n)
		{
			printf("\n\033[31m >>No hay tal numero! Elige un numero entre el 1 al %d!<<\033[0m\n", n);
			printf("Ingrese nuevamente el numero: ");
		}
	} while (i<1 || i>n);
	return i;
}

int VerificarCedula()  //Funcion para verficar acceso con cedula
{
	//Declaracion de Variables
	int i, buscar, persona;
	char cedula[15];
	
	//Bloque de instrucciones
	printf("Ingrese su numero de cedula: ");
	scanf("%s", &cedula);
	for(i=0; i<PERSONAS; i++)
    {
    	buscar = strcmp(cedula, todasLasCedulas[i]);
        if(buscar == 0)
    	{
    		persona=i;
            break;
        }
    }
    if(buscar == 0)
    {
    	system("cls");
        printf("\n                      %s %s tiene Acceso Confirmado!\n\n", todosLosNombres[persona], todosLosApellidos[persona]);
        return persona;
    }
    else
    {
        printf("no tiene Acceso\n");
        return -1;
	}
}

int Reservar(int personas, int mesas, int computadoras, int laboratorio[mesas][computadoras], int registro[personas][(mesas*computadoras)+1])  //Funcion para reservar computadora
{
	//Declaracion de variables
	int persona, mesa, computadora, seleccion=0;
	
	//Bloque de Instrucciones
	system("cls");
	do
	{
		persona=VerificarCedula();
		if(persona>=0)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			printf("Para realizar una reserva, seleccione una mesa y una computadora.\n");
			printf("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			printf("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			if (laboratorio[mesa-1][computadora-1] == 0)
			{
				system("cls");
				laboratorio[mesa-1][computadora-1] = 1;
				system("cls");
				printf("  __^__                                      __^__\n");
				printf(" ( ___ )------------------------------------( ___ )\n");
				printf("  | / |                                      | \\ |\n");
				printf("  | / |       \033[32mLA RESERVA FUE EXITOSA!!!\033[0m      | \\ |\n");
				printf("  |   |                                      |   |\n");
				printf("  | / |       Su lugar reservado es:         | \\ |\n");
				printf("  | / |       mesa %d y computadora %d!        | \\ |\n", mesa, computadora);
				printf("  |___|                                      |___|\n");
				printf(" (_____)------------------------------------(_____)\n"); 
				computadora=((mesa-1)*computadoras)+computadora;
				registro[persona][computadora]= registro[persona][computadora]+1;
				registro [persona][0]= registro [persona][0] + 1;
				return registro;
			}
			else
			{
				printf("\n\033[31m >>El lugar esta ocupado! ¡Elige otro!<<\033[0m\n");	
			}
		}
		else
		{
			do
			{
				system("cls");
				printf("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				printf("Desea volver a intentarlo?\n");
				printf("Digite 1 para si, 0 para salir: ");
				scanf("%d", &seleccion);
				if (seleccion<0 || seleccion>1)
				{
					printf("\n\033[31m >>No hay tal numero! Elige un numero entre el 0 y 1!<<\033[0m\n");
					system("PAUSE");
					
				}
			} while (seleccion<0 || seleccion>1);
			system("cls");
		}
	}while(seleccion==1);
	printf("Presione cualquier tecla para regresar\n");
}
	
int Cancelar(int mesas, int computadoras, int laboratorio[mesas][computadoras])  //Funcion para cancelar reserva de computadora
{
	//Declaracion de variables
	int mesa, computadora, persona, seleccion;
	
	//Bloque de Instrucciones
	system("cls");
	do
	{
		persona=VerificarCedula();
		if(persona>=0)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			printf("Para culminar una reserva, seleccione una mesa y una computadora.\n");
			printf("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			printf("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			if (laboratorio[mesa-1][computadora-1] == 1)
			{
				laboratorio[mesa-1][computadora-1] = 0;
				system("cls");
				printf("  __^__                                      __^__\n");
				printf(" ( ___ )------------------------------------( ___ )\n");
				printf("  | / |                                      | \\ |\n");
				printf("  | / |            \033[32mLA RESERVA SE\033[0m             | \\ |\n");
				printf("  | / |         \033[32mCANCELO CON EXITO!!!\033[0m         | \\ |\n");
				printf("  |   |                                      |   |\n");
				printf("  | / |     Se culmino su reservacion de:    | \\ |\n");
				printf("  | / |        mesa %d y computadora %d!       | \\ |\n", mesa, computadora);
				printf("  |___|                                      |___|\n");
				printf(" (_____)------------------------------------(_____)\n"); 
			}
			else
			{
				printf("\n\033[31m >>El lugar no esta reservado! Elige otro!<<\033[0m\n");	
			}
		}
		else
		{
			do
			{
				system("cls");
				printf("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				printf("Desea volver a intentarlo?\n");
				printf("Digite 1 para si, 0 para salir: ");
				scanf("%d", &seleccion);
				if (seleccion<0 || seleccion>1)
				{
					printf("\n\033[31m >>No hay tal numero! Elige un numero entre el 0 y 1!<<\033[0m\n");
					system("PAUSE");
					
				}
			} while (seleccion<0 || seleccion>1);
			system("cls");
		}
	}while(seleccion==1);
	printf("Presione cualquier tecla para regresar\n");
}

int ImprimirRegistro(int personas, int mesas, int computadoras, int registro[personas][(mesas*computadoras)+1])  //Funcion para imprimir el registro de reservas
{
	//Declacion de Variables
	int i, j, k, m, c, mesa, computadora, registro2D[mesas][computadoras]; //Nos toco revalorizar en otro arreglo 2D para hacer la imprecion, para no usar arreglos 3D
	
	//Bloque de Instrucciones
	system("cls");
	printf("\n Estas fueron las personas que reservaron computadoras:\n\n");
	printf("  __________________________________________ \n");
	printf(" | ________________________________________ |\n");

	for(i=0; i<PERSONAS; i++)
	{
		if(registro[i][0]>0)
		{
			if(i+1<10)
			{
				printf(" ||\033[32m#0%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				for(j=0; j<34-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					printf(" ");
				}
			}
			else if(i+1>=10 && i+1<100)
			{
				printf(" ||\033[32m#%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				for(j=0; j<34-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					printf(" ");
				}
			}
			else
			{
				printf(" ||\033[32m#%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				for(j=0; j<33-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					printf(" ");
				}
			}
			
			printf("||\n");
			printf(" ||========================================||\n");
			printf(" || Reservo estas computadoras:            ||\n");
			k=1;
			for(m=0;m<mesas;m++)
    		{
        		for(c=0;c<computadoras;c++)
        		{
            		registro2D[m][c] = registro[i][k];
            		k++;
        		}
    		}
    		for(m=0;m<mesas;m++)
    		{
        		for(c=0;c<computadoras;c++)
        		{
        			if(registro2D[m][c]>0)
        			{
        				if(m+1<10)
        				{
        					printf(" ||    Mesa %d, Computadora %d:   %d veces.   ||\n", m+1, c+1, registro2D[m][c]);
						}
						else
						{
							printf(" ||    Mesa %d, Computadora %d:  %d veces.   ||\n", m+1, c+1, registro2D[m][c]);
						}
        				
					}
        		}
    		}
    		if(registro[i][0]<10)
    		{
    			printf(" ||    con un total de:         %d reservas.||\n", registro[i][0]);
			}
			else
			{
    			printf(" ||    con un total de:         %d reservas.||\n", registro[i][0]);
    		}
    		printf(" ||________________________________________||\n");
		}
	}
	printf(" |__________________________________________|\n\n");
	printf("Presione cualquier tecla para regresar\n");		
}

int ImprimirListado()  //Funcion para imprimir listado de personas con acceso a reservas
{
	//Declaracion de Variables
	int i, j, k;
	
	//Bloque de Instrucciones
	system("cls");
	printf("Este es el listado de las personas autorizadas.\n");
	printf("  __________________________________________ \n");
	printf(" | ________________________________________ |\n");
	printf(" ||\033[32m #n  Nombres    Apellidos  Cedulas      \033[0m||\n");
	printf(" ||========================================||\n");
	for(i=0;i<PERSONAS; i++)
	{
		printf(" || ");
		if(i+1>=10)
		{
			printf("\033[33m%d\033[0m  ", i+1);
		}
		else
		{
			printf("\033[33m0%d\033[0m  ", i+1);
		}
		for(j=0; j<strlen(todosLosNombres[i]); j++)
		{
			printf("\033[33m%c\033[0m", todosLosNombres[i][j]);
		}
		for(k=0; k<11-strlen(todosLosNombres[i]); k++)
		{
			printf(" ");
		}
		for(j=0; j<strlen(todosLosApellidos[i]); j++)
		{
			printf("\033[33m%c\033[0m", todosLosApellidos[i][j]);
		}
		for(k=0; k<11-strlen(todosLosApellidos[i]); k++)
		{
			printf(" ");
		}
		for(j=0; j<strlen(todasLasCedulas[i]); j++)
		{
			printf("\033[33m%c\033[0m", todasLasCedulas[i][j]);
		}
		for(k=0; k<12-strlen(todasLasCedulas[i]); k++)
		{
			printf(" ");
		}
		printf(" ||\n");
	}
	printf(" ||________________________________________||\n");
	printf(" |__________________________________________|\n\n");
	printf("Presione cualquier tecla para regresar\n");
}

int ImprimirFin()
{
	system("cls");
		printf("\n");
		printf("  \033[35m########### ########### #############    ############ ################\033[0m       \n");
		printf("  \033[35m########### ########### #############    ############ ####################\033[0m    \n");
		printf("  \033[35m########### ########### #############    ############ ######################\033[0m  \n");
		printf("                \033[35m########                     ########                ##########\033[0m \n");
		printf("                \033[35m########                 \033[32m #  \033[35m########                   ########\033[0m\n");
		printf("  \033[32m######        \033[35m########              \033[32m ######\033[35m########\033[32m####                \033[35m#######\033[0m\n");
		printf(" \033[32m########       \033[35m########         \033[32m ###   # ###\033[35m########\033[32m##########          \033[35m#######\033[0m\n");
		printf("   \033[32m########    #\033[35m########   \033[32m ##############   \033[35m########\033[32m############       \033[35m########\033[0m\n");
		printf("  \033[32m##############\033[35m########\033[32m#################    \033[35m########  \033[32m############    \033[35m#########\033[0m\n");
		printf("   \033[32m#############\033[35m########\033[32m################     \033[35m######## #########################\033[0m \n");
		printf(" \033[32m###############\033[35m########\033[32m############         \033[35m######## #######################\033[0m   \n");
		printf(" \033[32m#            ##\033[35m\033[35m########\033[32m#######              \033[35m######## ####################\033[0m      \n");
		printf("                \033[35m########\033[32m###########          \033[35m########    \033[32m#############\033[0m          \n");
		printf("                \033[35m######## \033[32m###########         \033[35m########     \033[32m #########\033[0m            \n");
		printf("                \033[35m########  \033[32m###########        \033[35m########        \033[32m#### \033[0m              \n");
		printf("                 \033[35m########  \033[32m######           \033[35m#########                           \n");
		printf("                 \033[35m##########               ##########\033[0m                            \n");
		printf("                \033[35m#  ###############################  # \033[0m                          \n");
		printf("                \033[35m###  ###########################  ###\033[0m                           \n");
		printf("                \033[35m######  #####################  ###### \033[0m                          \n");
		printf("                \033[35m########                     ########\033[0m                           \n");
		printf("\n");
		printf("\033[33m  #####  ######     #     #####  ###    #     #####     ######  ####### ######  \n");
		 printf(" #     # #     #   # #   #     #  #    # #   #     #    #     # #     # #     # \n");
		 printf(" #       #     #  #   #  #        #   #   #  #          #     # #     # #     # \n");
		 printf(" #  #### ######  #     # #        #  #     #  #####     ######  #     # ######  \n");
		 printf(" #     # #   #   ####### #        #  #######       #    #       #     # #   #   \n");
		 printf(" #     # #    #  #     # #     #  #  #     # #     #    #       #     # #    #  \n");
		 printf("  #####  #     # #     #  #####  ### #     #  #####     #       ####### #     # \n");
		 printf("                                                                                \n");
		 printf("          #     # ####### ### #       ### #######    #    ######                \n");
		 printf("          #     #    #     #  #        #       #    # #   #     #               \n");
		 printf("          #     #    #     #  #        #      #    #   #  #     #               \n");
		 printf("          #     #    #     #  #        #     #    #     # ######                \n");
		 printf("          #     #    #     #  #        #    #     ####### #   #                 \n");
		 printf("          #     #    #     #  #        #   #      #     # #    #                \n");
		 printf("           #####     #    ### ####### ### ####### #     # #     #               \033[0m\n");
}

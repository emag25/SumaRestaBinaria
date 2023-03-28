#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>

using namespace std;

int SS[4], SR[4], n1[3], n2[2];

void gotoxy(int X, int Y);  // Permite ubicar el cursor en un determinado punto (x,y)
void color_txt(int colorf, int colort);  // Permite colorear el fondo y los caracteres individualmente
void ocultarse();    // Oculta el cursor de la consola
void botones_menu();  // Crea una simulacion de botones para el MENU (avanzar y salir)
void menu();       //  Imprime la pantalla del MENU
void botones_avanzar();// Crea una simulacion de botones para la pantalla AVANZAR (calcular, limpiar y menu)
void avanzar();   //  Imprime la pantalla AVANZAR

void ingreso();  // Pide los datos al usuario 
void suma();    // Realiza la operacion SUMA
void resta();   // Realiza la operacion RESTA
void presentar();  // Presenta los datos ingresados con su respectivo resultado

int main(){
	menu();
	getch();
	return 0;
}

void gotoxy(int X, int Y){
	HANDLE hCon; 
	COORD dwPos;
	dwPos.X = X;
	dwPos.Y = Y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void color_txt(int colorf, int colort){
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorf*16+colort); 
}

void ocultarse(){ 
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void botones_menu(){
	// CREACION BOTONES
	color_txt(15,0); gotoxy (43,24);  printf(" AVANZAR ");
	color_txt(9,15); gotoxy (65,24);  printf(" SALIR ");
	
	char boton;
	int casilla=1;
	// PARA DAR EL ENFOQUE A LOS BOTONES
	while(casilla!='f'){
	boton=getch();
	if(boton==77 && casilla==1) casilla=2;
	else if (boton==75 && casilla==1) casilla=2; 
	else if (boton==77 && casilla==1) casilla=2;	
	else if (boton==75 && casilla==2) casilla=1;
	else if (boton==77 && casilla==2) casilla=1;
	else if (casilla==1 && boton==13) casilla=3;
	else if (casilla==2 && boton==13) casilla=4;
	
	switch(casilla)
		{
		case 1: 
			color_txt(15,0); gotoxy (43,24);  printf(" AVANZAR ");
			color_txt(9,15); gotoxy (65,24);  printf(" SALIR ");
			break;
		case 2: 
			color_txt(9,15); gotoxy (43,24);  printf(" AVANZAR ");
			color_txt(15,0); gotoxy (65,24);  printf(" SALIR ");
			break;
		case 3:
			system("cls");
			ocultarse();
			avanzar();
			break;
		case 4:
			system("cls");
			exit(-1);
			casilla='f';	
			break;
		}
	}
}

void menu(){
	ocultarse(); 
	// CUADRO  
	system("color 0f");
	color_txt(12,12);
	gotoxy(3,1);  cout<<"__________________________________________________________________________________________________________________"; // linea superior
	gotoxy(3,28); cout<<"__________________________________________________________________________________________________________________"; // linea inferior
	for (int i=2;i<28;i++)
	{	
		gotoxy(3,i); cout<<"||";   // linea izquierda 
		gotoxy(115,i); cout<<"||";  // linea derecha 
	}
	color_txt(0,14);
	gotoxy (20,4);  printf("#### ##  ## ##     ## ######     ##    ##     #####   ##### #### ###### ######  ");
	gotoxy (20,5);  printf("#### ##  ## ###   ### ######      ##  ##      ##  ##  ##### #### ###### ######  ");
	gotoxy (20,6);  printf("##   ##  ## #### #### ##  ##       ####       ##  ##  ##    ##     ##   ##  ##  ");
	gotoxy (20,7);  printf("#### ##  ## ##  #  ## ##  ##        ##        #####   ####  ####   ##   ##  ##  ");
	gotoxy (20,8);  printf("#### ##  ## ##     ## ######        ##        #####   ####  ####   ##   ######  ");
	gotoxy (20,9); printf("  ## ##  ## ##     ## ##  ##        ##        ## ##   ##      ##   ##   ##  ##   ");
	gotoxy (20,10); printf("#### ###### ##     ## ##  ##        ##        ##  ##  ##### ####   ##   ##  ##  ");
	gotoxy (20,11); printf("#### ###### ##     ## ##  ##        ##        ##   ## ##### ####   ##   ##  ##  ");
	
	gotoxy(20,13); printf("######    #####     ######  ###### ##     ## ###### #####   ###### ###### ####   ");
	gotoxy(20,14); printf("##   ##   #####     ##   ## ###### ###    ## ###### ##  ##  ###### ###### ####   ");
	gotoxy(20,15); printf("##    ##  ##        ##   ##   ##   ####   ## ##  ## ##  ##    ##   ##  ## ##     ");
	gotoxy(20,16); printf("##     ## ####      ######    ##   ## ##  ## ##  ## #####     ##   ##  ## ####  ");
	gotoxy(20,17); printf("##     ## ####      ######    ##   ##  ## ## ###### #####     ##   ##  ## ####   ");
	gotoxy(20,18); printf("##    ##  ##        ##   ##   ##   ##   #### ##  ## ## ##     ##   ##  ##   ##  ");
	gotoxy(20,19); printf("##   ##   #####     ##   ## ###### ##    ### ##  ## ##  ##  ###### ###### ####");
	gotoxy(20,20); printf("######    #####     ######  ###### ##     ## ##  ## ##   ## ###### ###### ####");
	botones_menu();	
}

void botones_avanzar(){
	// CREACION DE BOTONES
	system("color 0");
	color_txt(15,0);
	gotoxy(72,4); printf(" CALCULAR "); 
	color_txt(9,15);
	gotoxy(84,6); printf(" MENU ");
	gotoxy(92,4); printf(" LIMPIAR ");
	
	int casilla=1;
	char boton;
	// PARA DAR EL ENFOQUE A LOS BOTONES
	while(casilla!='f'){
		boton=getch();
		if(boton==80 && casilla==1) casilla=2;
		else if (boton==72 && casilla==1) casilla=2;
		else if (boton==72 && casilla==2) casilla=1;
		else if (boton==80 && casilla==2) casilla=1;
			
		else if (boton==77 && casilla==1) casilla=3;
		else if (boton==75 && casilla==1) casilla=3;
		else if (boton==77 && casilla==2) casilla=2;
		else if (boton==75 && casilla==2) casilla=2;
		
		else if (boton==75 && casilla==3) casilla=1;
		else if (boton==77 && casilla==3) casilla=1;
		else if (boton==75 && casilla==4) casilla=2;
		else if (boton==77 && casilla==4) casilla=2;
		
		else if (boton==80 && casilla==3) casilla=2;
		else if (boton==72 && casilla==3) casilla=2;
	
		else if (casilla==1 && boton==13) casilla=4;
		else if (casilla==2 && boton==13) casilla=5;
		else if (casilla==3 && boton==13) casilla=6;
	
		switch(casilla){
			case 1: color_txt(15,0);
				gotoxy(72,4); printf(" CALCULAR ");
				color_txt(9,15);
				gotoxy(84,6); printf(" MENU ");
				gotoxy(92,4); printf(" LIMPIAR ");
			break;
			case 2: color_txt(9,15);
				gotoxy(72,4); printf(" CALCULAR ");
				gotoxy(92,4); printf(" LIMPIAR ");
				color_txt(15,0);
				gotoxy(84,6); printf(" MENU ");
			break;
			case 3: color_txt(9,15);
				gotoxy(72,4); printf(" CALCULAR ");
				gotoxy(84,6); printf(" MENU ");
				color_txt(15,0);
				gotoxy(92,4); printf(" LIMPIAR ");
			break;
			case 4: //para caso boton calcular
				system("color 0");
				presentar();
				break;
			
			case 5: //para caso boton Menu
				system("cls");
				menu();
				casilla = 'f';
				break;
			case 6: //para caso boton limpiar pantalla
				system("cls");
				avanzar();
				break;
		}
	}
}

void avanzar(){
	system("color 0f");
	// CUADRO O MARCO
	color_txt(12,12);
	gotoxy(3,1);  cout<<"__________________________________________________________________________________________________________________"; // linea superior
	gotoxy(3,28); cout<<"__________________________________________________________________________________________________________________"; // linea inferior
	for (int i=2;i<28;i++)
	{	
		gotoxy(3,i); cout<<"||";   // linea izquierda 
		gotoxy(115,i); cout<<"||";  // linea derecha 
	}
	//LINEAS HORIZONTALES
	color_txt(0,10);
	for (int i=10;i<=109;i++){
		gotoxy(i,9); printf("=");
	}
	for (int i=10;i<=109;i++){
		gotoxy(i,26); printf("=");
	}
	for (int i=10;i<=109;i++){
		gotoxy(i,15); printf("=");
	}
	//LINEAS VERTICALES
	for (int i=10;i<26;i++){
		gotoxy(10,i); printf("||");
	}
	for (int i=10;i<26;i++){
		gotoxy(108,i); printf("||");
	}
	for(int i=10;i<26;i++){
		gotoxy(58,i); printf("||");
	}
	color_txt(0,15);
	gotoxy(21,10); printf("#### ##  ## ##   ## ######");
	gotoxy(21,11); printf("##   ##  ## ### ### ##  ##");
	gotoxy(21,12); printf("#### ##  ## ## # ## ######");
	gotoxy(21,13); printf("  ## ##  ## ##   ## ##  ##");
	gotoxy(21,14); printf("#### ###### ##   ## ##  ##");
	
	gotoxy(69,10); printf("#####  ##### #### ###### ######");
	gotoxy(69,11); printf("##  ## ##    ##     ##   ##  ##");
	gotoxy(69,12); printf("#####  ###   ####   ##   ######");
	gotoxy(69,13); printf("## ##  ##      ##   ##   ##  ##");
	gotoxy(69,14); printf("##  ## ##### ####   ##   ##  ##");
	ingreso(); 
}

void ingreso(){
	gotoxy(10,4);printf("INGRESE LA PRIMERA CIFRA: ");
	
	char presiona;
	int numero=0;
	// INGRESA EL DIGITO 1 DE LA 1ERA CIFRA
	while(numero!='k'){
	presiona=getch();
	if(presiona=='1' && numero==0) numero=1;
	else if (presiona=='0' && numero==0) numero=2;
	
		switch(numero)
		{
			case 0:
		break;
			
		case 1:
			n1[0]=1;
			gotoxy(40,4); cout<<'1';
			numero='k';
		break;
		
		case 2:
			n1[0]=0;
			gotoxy(40,4); cout<<'0';
			numero='k';
		break;
		}
	}
	numero=0;
	// INGRESA EL DIGITO 2 DE LA 1ERA CIFRA
	while(numero!='k'){
	presiona=getch();
	if(presiona=='1' && numero==0) numero=1;
	else if (presiona=='0' && numero==0) numero=2;
	
		switch(numero)
		{
			case 0:
		break;
			
		case 1:
			n1[1]=1;
			gotoxy(42,4); cout<<'1';
			numero='k';
		break;
		
		case 2:
			n1[1]=0;
			gotoxy(42,4); cout<<'0';
			numero='k';
		break;
		}
	}
	numero=0;
	// INGRESA EL DIGITO 3 DE LA 1ERA CIFRA
	while(numero!='k'){
	presiona=getch();
	if(presiona=='1' && numero==0) numero=1;
	else if (presiona=='0' && numero==0) numero=2;
	
		switch(numero)
		{
			case 0:
		break;
			
		case 1:
			n1[2]=1;
			gotoxy(44,4); cout<<'1';
			numero='k';
		break;
		
		case 2:
			n1[2]=0;
			gotoxy(44,4); cout<<'0';
			numero='k';
		break;
		}
	}
	numero=0;
	
	gotoxy(10,6);printf("INGRESE LA SEGUNDA CIFRA: ");
	// INGRESA EL DIGITO 1 DE LA 2DA CIFRA
	while(numero!='k'){
	presiona=getch();
	if(presiona=='1' && numero==0) numero=1;
	else if (presiona=='0' && numero==0) numero=2;
	
		switch(numero)
		{
			case 0:
		break;
			
		case 1:
			n2[0]=1;
			gotoxy(42,6); cout<<'1';
			numero='k';
		break;
		
		case 2:
			n2[0]=0;
			gotoxy(42,6); cout<<'0';
			numero='k';
		break;
		}
	}
	numero=0;
	// INGRESA EL DIGITO 2 DE LA 2DA CIFRA
	while(numero!='k'){
	presiona=getch();
	if(presiona=='1' && numero==0) numero=1;
	else if (presiona=='0' && numero==0) numero=2;
	
		switch(numero)
		{
			case 0:
		break;
			
		case 1:
			n2[1]=1;
			gotoxy(44,6); cout<<'1';
			numero='k';
		break;
		
		case 2:
			n2[1]=0;
			gotoxy(44,6); cout<<'0';
			numero='k';
		break;
		}
	}
	botones_avanzar();
}

void suma(){
	SS[0] = (n1[0]&&n1[1]&&n2[0]) || (n1[0]&&n1[1]&&n1[2]&&n2[1]) || (n1[0]&&n1[2]&&n2[0]&&n2[1]);
	SS[1] = (!n1[0]&&n1[1]&&n1[2]&&n2[1]) || (!n1[0]&&n1[2]&&n2[0]&&n2[1]) || (!n1[0]&&n1[1]&&n2[0]) || (n1[0]&&!n1[2]&&!n2[0]) || (n1[0]&&!n2[0]&&!n2[1]) || (n1[0]&&!n1[1]&&!n2[1]) || (n1[0]&&!n1[1]&&!n2[0]) || (n1[0]&&!n1[1]&&!n1[2]);
	SS[2] = (n1[1]&&!n2[0]&&!n2[1]) || (!n1[1]&&n1[2]&&!n2[0]&&n2[1]) || (n1[1]&&!n1[2]&&!n2[0]&&n2[1]) || (n1[1]&&n1[2]&&n2[0]&&n2[1]) || (!n1[1]&&!n1[2]&&n2[0]) || (!n1[1]&&n2[0]&&!n2[1]);
	SS[3] = (n1[2]&&!n2[1]) || (!n1[2]&&n2[1]);
}

void resta(){
	SR[0] = (!n1[0]&&!n1[1]&&n2[0]) || (!n1[0]&&!n1[1]&&!n1[2]&&n2[1]) || (!n1[0]&&!n1[2]&&n2[0]&&n2[1]);
	SR[1] = (n1[0]&&!n2[0]&&!n2[1]) || (n1[0]&&n1[1]&&!n2[0]) || (n1[0]&&n1[2]&&!n2[0]) || (n1[0]&&n1[1]&&n1[2]) || (n1[0]&&n1[1]&&!n2[1]);
	SR[2] = (n1[1]&&!n2[0]&&!n2[1]) || (n1[1]&&n1[2]&&!n2[0]) || (!n1[1]&&n1[2]&&n2[0]&&n2[1]) || 	(!n1[0]&&!n1[1]&&!n1[2]&&n2[0]) || (n1[0]&&!n1[1]&&n2[0]&&!n2[1]) || (n1[0]&&n1[1]&&!n1[2]&&n2[0]&&n2[1]) || (n1[0]&&!n1[1]&&!n1[2]&&!n2[0]&&n2[1]); 
	SR[3] = (n1[2]&&!n2[1]) || (!n1[2]&&n2[1]);
}

void presentar(){
	color_txt(0,15);
	//  SUMA                     RESTA
	gotoxy(32,18);cout<<n1[0];  gotoxy(82,18);cout<<n1[0];
	gotoxy(35,18);cout<<n1[1];	gotoxy(85,18);cout<<n1[1];
	gotoxy(38,18);cout<<n1[2];	gotoxy(88,18);cout<<n1[2];
	gotoxy(35,20);cout<<n2[0];	gotoxy(85,20);cout<<n2[0];
	gotoxy(38,20);cout<<n2[1];	gotoxy(88,20);cout<<n2[1];
	gotoxy(29,20);cout<<"+"; gotoxy(27,21);cout<<"______________";
	gotoxy(79,20);cout<<"-"; gotoxy(77,21);cout<<"______________";
	// RESULTADO SUMA
	suma();
	gotoxy(29,23);cout<<SS[0];
	gotoxy(32,23);cout<<SS[1];
	gotoxy(35,23);cout<<SS[2];
	gotoxy(38,23);cout<<SS[3];
	// RESULTADO RESTA
	resta();
	gotoxy(79,23);cout<<SR[0];
	gotoxy(82,23);cout<<SR[1];
	gotoxy(85,23);cout<<SR[2];
	gotoxy(88,23);cout<<SR[3];
}


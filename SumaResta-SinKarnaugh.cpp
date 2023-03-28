#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct operaciones
{
    int resultado;
    int acarreo;
};


operaciones suma(int, int);
operaciones resultado_suma(int, int, int);
int mainsuma (int[], int[]);

operaciones resta(int, int);
operaciones resultado_resta(int, int, int);
int mainresta (int[], int[]);

int main() {
    
	int numero1[3];
    numero1[0] = 1;
    numero1[1] = 1;
    numero1[2] = 1;
    
	int numero2[3];
    numero2[0] = 0;
    numero2[1] = 1;
    numero2[2] = 1;
    
	mainsuma(numero1, numero2);
    
	
	int numero3[3];
    numero3[0] = 0;
    numero3[1] = 0;
    numero3[2] = 1;
    
	int numero4[3];
    numero4[0] = 0;
    numero4[1] = 1;
    numero4[2] = 1;
    mainresta(numero3, numero4);
    
    getch();
	return 0;
}

//Funciones para las operaciones suma
operaciones suma(int numero1, int numero2) {
    operaciones salida;
    int resultado = 0, acarreo = 0;
    if (numero1 != numero2)
    {
        resultado = 1;
    }
    if (numero1 == 1 && numero2 == 1){
        acarreo = 1;
    }
    salida.resultado = resultado;
    salida.acarreo = acarreo;
    return salida;
}

operaciones resultado_suma (int numero1, int numero2, int carry){
    operaciones salida;
    int resultado = 0;
    int acarreo = 0;
    if (carry == 1) {
        salida = suma(carry, numero1);
        if (salida.acarreo ==1) {
            int temp = salida.acarreo;
            salida = suma(salida.resultado, numero2);
            salida.acarreo = temp;
        }
        else
        {
            salida = suma(salida.resultado, numero2);
        }
    
    }else
    {
        salida = suma(numero1, numero2);
 
    }
    return salida;
}

int mainsuma(int numero1[], int numero2[]){
    int resultado[4];
    operaciones salida;
    salida.acarreo=0;
    for(int i=0;i<3;i++){
        int num1 = numero1[3-i-1];
        int num2 = numero2[3-i-1];
        salida=resultado_suma(num1, num2, salida.acarreo);
        if ((i+1)==3) {
            if (salida.acarreo == 1) {
                if (!(num1==0 && num2==0)) {
                    resultado[0]= 1;
                }
            }else{
                resultado[0]= 0;
            }
        }
        resultado[3-i]=salida.resultado;

    }
    printf("Resultado suma: ");
    for(int i=0;i<4;i++){
        printf("%d",resultado[i]);
    }
    printf("\n");
    return 0;
}

//Funciones para las operaciones resta
operaciones resta(int numero1, int numero2) {
    operaciones salida;
    int resultado = 0, acarreo = 0;
    if (numero1 != numero2)
    {
        resultado = 1;
    }
    if (numero1 == 0 && numero2 == 1){
        acarreo = 1;
    }
    salida.resultado = resultado;
    salida.acarreo = acarreo;
    return salida;
}

operaciones resultado_resta (int numero1, int numero2, int carry){
    operaciones salida;
    int resultado = 0, acarreo = 0;
    if (carry == 1) {
        salida = resta(numero1,carry);
        if (salida.acarreo ==1) {
            int temp = salida.acarreo;
            salida = resta(salida.resultado, numero2);
            salida.acarreo = temp;
        }
        else
        {
            salida = resta(salida.resultado, numero2);
        }
    
    }else
    {
        salida = resta(numero1, numero2);
 
    }
    return salida;
}

int mainresta(int numero1[], int numero2[]){
    
	int resultado[4];
    operaciones salida;
    salida.acarreo=0;
    for(int i=0;i<3;i++){
        int num1 = numero1[3-i-1];
        int num2 = numero2[3-i-1];
        salida=resultado_resta(num1, num2, salida.acarreo);
        if ((i+1)==3) {
            if (salida.acarreo == 1) {
                if (!(num1==1 && num2==0)) {
                    resultado[0]= 1;
                }
            }else{
                resultado[0]= 0;
            }
        }
        resultado[3-i]=salida.resultado;

    }
    printf("Resultado resta: ");
    for(int i=0;i<4;i++){
        printf("%d",resultado[i]);
    }
    printf("\n");
    
	return 0;
}


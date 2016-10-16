//
//  main.c
//  determinant calculation
//
//  Created by shivam sachdeva on 29/08/14.
//  Copyright (c) 2014 shivam sachdeva and Akash mehra. All rights reserved.
//

#include <stdio.h>
#include <conio.h>
void pointer(int *x1,int *x2,int *x3,int *x4,int *x5,int *x6,int *x7,int *x8,int *x9);
void det3();
void det4();
void cof();
void inv();
void rank33();
void unk();
void rank();
void rank34();
void rank43();
void add();
void det_1();
void multiply();
int i,j,det,a[40][40],c[40][40],adj[30][30];//Global Variables

int main()
{
    printf("------------choose any one of the given options----------\n");
    printf("1. Determinant of a matrix \n2. Find the rank of a matrix \n3. Cofactors and adjoints of a 3x3 matrix\n4. Finding the inverse of a 3x3 matrix(includes value of determinant,cofactors and adjoint too)\n 5.Find the value of unknowns \n6. Addition and subtraction of 2 matrices\n7. Multiplication of 2 3x3 matrices\n");
    int c1;
    printf("\n\nyour input = ");
    scanf("%d",&c1);
    switch (c1)
    {

            case 1: //Determinant calculation
            det_1();
            break;

            case 2://RANK OF A MATRIX
            rank();
            break;

            case 3://TO find the  the co factors and adjoints of a 3x3 matrix
            cof();
            break;

            case 4: //INVERSE OF A 3X3 MATRIX
            inv();
            break;


            case 5://TO FIND THE VALUE OF UNKOWNES
            unk();
            break;

            case 6://Addition and subtraction of 2 matrices
            add();
            break;

            case 7://MULTIPLICATION OF 2 3X3 MATRICES
            multiply();
            break;

            default:
            printf("wrong input\n");
            break;


    } getch();
    return 0;}


void det_1()//Nested switch for determinant calculation
{int ch;
     printf("\n\n=========MENU========\n1.  Determinant of a 3x3\n2.  Determinant of a 4x4\n ");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
            det3();
            break;
        case 2:
            det4();
            break;
        default:
            printf("wrong input");
            break;
    }


}

//determinant value of a 3x3 matrix (function)-----

void det3()
{  FILE *det3x3;
   det3x3=fopen("C:/Users/shivam/Desktop/matrix program/Determinant3x3.txt","a+");
    printf("----calculating the determinant value of a 3x3 matrix----\n\n");
    for (i=0;i<3;i++)

    {
        for (j=0;j<3;j++)

        {printf("input a%d%d = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }}
    det=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    printf("Determinant value of this 3x3 matrix = %d\n",det);

    fprintf(det3x3,"\n----Matrix----\n");
    for (i=0;i<3;i++)

    {
        for (j=0;j<3;j++)

        {
            fprintf(det3x3,"%d\t",a[i][j]);

        }
        fprintf(det3x3,"..\n");
    }
 fprintf(det3x3,"Determinant = %d",det);
 fclose(det3x3);
}

//determinant value of a 4x4 matrix (function)--------

void det4()
{
    printf("---- calculating the determinant value of a 4x4 matrix----n\n");
    for (i=0;i<4;i++)

    {
        for (j=0;j<4;j++)

        {printf("input a%d%d = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }}
    det=a[0][0]*(a[1][1]*(a[2][2]*a[3][3]-a[2][3]*a[3][2])-a[1][2]*(a[2][1]*a[3][3]-a[2][3]*a[3][1])+a[1][3]*(a[2][1]*a[3][2]-a[2][2]*a[3][1]))-a[0][1]*(a[1][0]*(a[2][2]*a[3][3]-a[2][3]*a[3][2])-a[1][2]*(a[2][0]*a[3][3]-a[2][3]*a[3][0])+a[1][3]*(a[2][0]*a[3][2]-a[3][0]*a[2][2]))+a[0][2]*(a[1][0]*(a[2][1]*a[3][3]-a[2][3]*a[3][1])-a[1][1]*(a[2][0]*a[3][3]-a[2][3]*a[3][0])+a[1][3]*(a[2][0]*a[3][1]-a[2][1]*a[3][0]))-a[0][3]*(a[1][0]*(a[2][1]*a[3][2]-a[2][2]*a[3][1])-a[1][1]*(a[2][0]*a[3][2]-a[2][2]*a[3][0])+a[1][2]*(a[2][0]*a[3][1]-a[2][1]*a[3][0]));
    printf("Determinant value of this 4x4 matrix = %d\n",det);}

//coffactors and adjoints(functions)-------


void cof()
 {printf("-----Input the matrix-----\n");//SCANNING 9 MATRIX ELEMENTS
     for (i=0;i<3;i++)

     {
         for (j=0;j<3;j++)

         { printf("input a%d%d = ",i+1,j+1);
             scanf("%d",&a[i][j]);}}
              pointer(&c[0][0],&c[0][1],&c[0][2],&c[1][0],&c[1][1],&c[1][2],&c[2][0],&c[2][1],&c[2][2]);//Cofactos

     printf("----CoFactors----");//PRINTING COFACTORS
     for (i=0;i<3;i++)

     {
         for (j=0;j<3;j++)

          { printf("\n\ninput c%d%d = %d\n",i+1,j+1,c[i][j]);
                 }}

     printf("\n----ADJOINTS----");//PRINTING ADJOINTS


     for(i=0;i<3;i++)//swapping values f
     {for (j=0;j<3;j++)
     {adj[i][j]=c[j][i];
         printf("\na %d%d = %d",i+1,j+1,adj[i][j]);
     }}

}

//inverse of a 3x3 matrix(functions)--------


void inv()
{ printf("----INPUT THE ELEMENTS OF THE MATRIX----\n\n");
    for (i=0;i<3;i++)

    {
        for (j=0;j<3;j++)

        {printf("input a number %d%d = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }}
    det=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]); //formula for 3x3 determinant's value

    pointer(&c[0][0],&c[0][1],&c[0][2],&c[1][0],&c[1][1],&c[1][2],&c[2][0],&c[2][1],&c[2][2]);
    printf("%d\n",det);
    if (det==0) {printf("the determiant has no inverse ");}
    else
    { printf("----CoFactors----");//PRINTING COFACTORS
        for (i=0;i<3;i++)

        {
            for (j=0;j<3;j++)

            { printf("\nc%d%d = %d",i+1,j+1,c[i][j]);
            }}


        printf("\n----ADJOINTS----");//PRINTING ADJOINTS


        for(i=0;i<3;i++)//swapping values f
        {for (j=0;j<3;j++)
        {adj[i][j]=c[j][i];
            printf("\na %d%d = %d",i+1,j+1,adj[i][j]);
        }}

        printf("\n----INVERSE----\n");//PRINTING THE INVERSE

        for(i=0;i<3;i++)
        {for (j=0;j<3;j++)
        { printf("\na%d%d = %d/%d",i+1,j+1,adj[i][j],det);} }}}

 //rank of a 3x3 matrix(functions)-------

 void rank33()
  {
      printf("----calculating the determinant value of a 3x3 matrix ----\n\n");

            int det1,det2,det3,det4,det5,det6,det7,det8;
                   for (i=0;i<3;i++)
                        {
                         for (j=0;j<3;j++)
                           {printf("input a%d%d = ",i+1,j+1);
                                 scanf("%d",&a[i][j]);}}
    printf("determinant value of the determinant = ");
    det=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    printf("%d\n",det);
    if(det!=0)
    {printf("The rank of the matrix is 3\n");}


    if(det==0&&(det1!=0||det2!=0||det3!=0||det4!=0||det5!=0||det6!=0||det7!=0||det8!=0))
    {   det1=a[0][0]*a[1][1]-a[0][1]*a[1][0];
        det2=a[0][1]*a[1][2]-a[0][2]*a[1][1];
        det3=a[0][0]*a[1][2]-a[0][2]*a[1][0];
        det4=a[1][0]*a[1][1]-a[2][0]*a[2][1];
        det5=a[1][1]*a[2][2]-a[1][2]*a[2][1];
        det6=a[1][0]*a[2][2]-a[1][2]*a[2][0];
        det7=a[0][0]*a[2][1]-a[0][1]*a[2][0];
        det8=a[0][1]*a[2][2]-a[0][2]-a[2][1];
        printf("the rank of the matrix is 2\n");}

    if (det==0&&(det1==0||det2==0||det3==0||det4==0||det5==0||det6==0||det7==0||det8==0))
    {printf("the rank of the matrix is 1\n");}
}

// value of unknowns(function)-------

void unk()
{
    printf("The value of unknowns(x,y,z)\n");
    for (i=0;i<3;i++)

    {
        for (j=0;j<3;j++)

        {printf("input a%d%d = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }}

    int b11,b21,b31,x,y,z,x1,y1,z1;
    printf("Here b11,b21 and are b31 are the elements of the 3x1 matrix\n");
    printf("\ninput the value of b11 = ");
    scanf("%d",&b11);
    printf("\ninput the value of b21 = ");
    scanf("%d",&b21);
    printf("\ninput the value of b31 = ");
    scanf("%d",&b31);
    printf("determinant value of the determinant = ");
    det=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    printf("%d\n",det);

    pointer(&c[0][0],&c[0][1],&c[0][2],&c[1][0],&c[1][1],&c[1][2],&c[2][0],&c[2][1],&c[2][2]);//gettiing cofactors value
    printf("----CoFactors----");//PRINTING COFACTORS
    for (i=0;i<3;i++)

    {
        for (j=0;j<3;j++)

        { printf("\nc%d%d = %d",i+1,j+1,c[i][j]);
        }}
    printf("\n----ADJOINTS----");//PRINTING ADJOINTS


    for(i=0;i<3;i++)//swapping values f
    {for (j=0;j<3;j++)
    {adj[i][j]=c[j][i];
        printf("\na %d%d = %d",i+1,j+1,adj[i][j]);
    }}


    if (det!=0) {


        printf("\n----INVERSE----\n");//PRINTING THE INVERSE

        for(i=0;i<3;i++)
        {for (j=0;j<3;j++)
        { printf("\na%d%d = %d/%d",i+1,j+1,adj[i][j],det);}}

        printf("\nUSING THE EQUATION X=A^-1XB\n");

        x=(adj[0][0]*b11+adj[0][1]*b21+adj[0][2]*b31)/det;
        x1=adj[0][0]*b11+adj[0][1]*b21+adj[0][2]*b31;
        y=(adj[1][0]*b11+adj[1][1]*b21+adj[1][2]*b31)/det;
        y1=adj[1][0]*b11+adj[1][1]*b21+adj[1][2]*b31;
        z=(adj[2][0]*b11+adj[2][1]*b21+adj[2][2]*b31)/det;
        z1=adj[2][0]*b11+adj[2][1]*b21+adj[2][2]*b31;
        if ((adj[0][0]*b11+adj[0][1]*b21+adj[0][2]*b31)>det||(adj[0][0]*b11+adj[0][1]*b21+adj[0][2]*b31)==det)
            printf("\n x = %d",x);
        else
            printf("\n x = %d/%d",x1,det);
        if((adj[1][0]*b11+adj[1][1]*b21+adj[1][2]*b31>det||(adj[1][0]*b11+adj[1][1]*b21+adj[1][2]*b31)==det))
            printf("\n y = %d",y);
        else
            printf("\n y = %d/%d",y1,det);
        if ((adj[2][0]*b11+adj[2][1]*b21+adj[2][2]*b31)>det||(adj[2][0]*b11+adj[2][1]*b21+adj[2][2]*b31)==det)
            printf("\n z = %d\n",z);
        else
            printf("\n z = %d/%d",z1,det);

    }

    else
    {{printf("\n adjA.b\n");}
        int adjA_b;
        adjA_b=c[0][0]*b11+c[0][1]*b21+c[0][2]*b31+c[1][0]*b11+c[1][1]*b21+c[1][2]*b31+c[2][0]*b11+c[2][1]*b21+c[2][2]*b31;

        if (adjA_b==0)
        {printf("The matrix has an infinite number of solutions\n");}

        else
        {printf("The matrix has no solution\n");}}}


//RANK SWITCHER----

void rank()
{
    int ch;
    printf("\n\n=========MENU========\n1.  Rank of a 3x3 matrix\n2.  Rank of a 3x4 matrix\n3.  Rank of a 4x3 amtrix\n ");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
            rank33();
            break;
        case 2:
            rank34();
            break;
        case 3:
            rank43();
            break;
        default:
            printf("wrong input");
            break;
    }



}


// to find the rank of 3x4 matrix(function)-----


void rank34()
{ printf("----RANK OF A 3X4 MATRIX----\n");
    int det1,det2,det3,det4,det5,det6,det7,det8,det9,det10,det11,det12,det13,det14,det15,det16,det17,det18,det19,det20,det21,det22,det23,det_1;
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++) {
            printf("Input a%d%d = ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    det1=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
    det2=a[0][1]*(a[1][2]*a[2][3]-a[1][3]*a[2][2])-a[0][2]*(a[1][1]*a[2][3]-a[1][3]*a[2][1])+a[0][3]*(a[1][1]*a[2][2]-a[1][2]*a[2][1]);
    det3=a[0][0]*(a[1][2]*a[2][3]-a[1][3]*a[2][2])-a[0][2]*(a[1][0]*a[2][3]-a[1][3]*a[2][0])+a[0][3]*(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
    det4=a[0][0]*(a[1][1]*a[2][3]-a[1][3]*a[2][1])-a[0][1]*(a[1][0]*a[2][3]-a[1][3]*a[2][0])+a[0][3]*(a[1][0]*a[2][1]-a[2][0]*a[1][1]);
    det_1=det1+det2+det3+det4;
    det5=a[0][0]*a[1][1]-a[0][1]*a[1][0];
    det6=a[0][1]*a[1][2]-a[0][2]*a[1][1];
    det7=a[0][2]*a[1][3]-a[0][3]*a[1][2];
    det8=a[1][0]*a[2][1]-a[1][1]*a[2][0];
    det9=a[1][1]*a[2][2]-a[1][2]*a[2][1];
    det10=a[1][2]*a[2][3]-a[1][3]*a[2][2];
    det11=a[0][0]*a[0][1]-a[2][0]*a[2][1];
    det12=a[0][1]*a[2][2]-a[0][2]*a[2][1];
    det13=a[0][2]*a[2][3]-a[0][3]*a[2][2];
    det14=a[0][0]*a[2][2]-a[0][2]*a[2][0];
    det15=a[0][0]*a[2][3]-a[0][3]*a[2][0];
    det16=a[0][1]*a[2][2]-a[0][2]*a[2][1];
    det17=a[0][1]*a[2][3]-a[0][3]*a[2][1];
    det18=a[0][0]*a[1][2]-a[0][2]*a[1][0];
    det19=a[0][1]*a[1][3]-a[0][3]*a[1][1];
    det20=a[1][0]*a[2][2]-a[1][2]*a[2][0];
    det21=a[1][1]*a[2][3]-a[1][3]*a[2][1];
    det22=a[0][0]*a[1][3]-a[0][3]*a[1][0];
    det23=a[1][0]*a[2][3]-a[1][3]*a[2][0];
    printf("deterinant value of 3x3 matrix = %d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\n",det1,det2,det3,det4,det5,det6,det7,det8,det9,det10,det11,det12,det13,det14,det15,det16,det17,det18,det19,det20,det21,det22,det23);
    if (det1!=0||det2!=0||det3!=0||det4!=0) {
        printf("\n\n\nThe rank of the determinant is 3\n");
    }
    if (det_1==0&&(det5!=0||det6!=0||det7!=0||det8!=0||det9!=0||det10!=0||det11!=0||det12!=0||det13!=0||det14!=0||det15!=0||det16!=0||det17!=0||det18!=0||det19!=0||det20!=0||det21!=0||det22!=0||det23!=0))
    {printf("\n\n\nThe rank of the matrix is 2\n");}
    if (det_1==0&&(det5==0&&det6==0&&det7==0&&det8==0&&det9==0&&det10==0&&det11==0&&det12==0&&det13==0&&det14==0&&det15==0&&det16==0&&det17==0&&det18==0&&det19==0&&det20==0&&det21==0&&det22==0&&det23==0))
    {
        printf("\n\n\nThe rank of the matrix is 1\n");
    }


}


// to find the rank of a4x3 matrix(function)------

void rank43()
{ printf("----RANK OF A 4X3 MATRIX----\n");
    int det1,det2,det3,det4,det5,det6,det7,det8,det9,det10,det11,det12,det13,det14,det15,det16,det17,det18,det19,det20,det21,det22,det_1;
for (i=0; i<4; i++) {
    for (j=0; j<3; j++) {
        printf("Input a%d%d = ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
}
det1=a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])-a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])+a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);
det2=a[1][0]*(a[2][1]*a[3][2]-a[3][1]*a[2][2])-a[1][1]*(a[2][0]*a[3][2]-a[3][0]*a[2][2])+a[1][2]*(a[2][0]*a[3][1]-a[2][1]*a[3][0]);
det3=a[0][0]*(a[2][1]*a[3][2]-a[3][1]*a[2][2])-a[0][1]*(a[2][0]*a[3][2]-a[2][2]*a[3][0])+a[0][2]*(a[2][0]*a[3][1]-a[3][0]*a[2][1]);
det4=a[0][0]*(a[1][1]*a[3][2]-a[1][2]*a[3][1])-a[0][1]*(a[1][0]*a[3][2]-a[1][2]*a[3][0])+a[0][2]*(a[1][0]*a[3][1]-a[3][0]*a[1][1]);
det_1=det1+det2+det3+det4;
det5=a[0][0]*a[1][1]-a[0][1]*a[1][0];
det6=a[0][1]*a[1][2]-a[0][2]*a[1][1];
det7=a[1][0]*a[2][1]-a[1][1]*a[2][0];
det8=a[1][1]*a[2][2]-a[1][2]*a[2][1];
det9=a[2][0]*a[3][1]-a[2][1]*a[3][0];
det10=a[2][1]*a[3][2]-a[3][1]*a[2][2];
det11=a[2][0]*a[3][2]-a[2][2]*a[3][0];
det12=a[1][0]*a[2][2]-a[1][2]*a[2][0];
det13=a[0][0]*a[1][2]-a[0][2]*a[1][0];
det14=a[0][0]*a[2][1]-a[0][1]*a[2][0];
det15=a[1][0]*a[3][1]-a[3][0]*a[1][1];
det16=a[0][1]*a[2][2]-a[0][2]*a[2][1];
det17=a[1][1]*a[3][2]-a[1][2]*a[3][1];
det18=a[0][0]*a[3][1]-a[0][1]*a[3][0];
det19=a[0][1]*a[3][2]-a[0][2]*a[3][1];
det20=a[1][0]*a[2][2]-a[1][2]*a[2][0];
det21=a[0][0]*a[2][2]-a[0][2]*a[2][0];
det22=a[0][1]*a[2][2]-a[0][2]*a[2][1];
printf("deterinant value of 3x3 matrix = %d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 3x3 matrix =%d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\ndeterinant value of 2x2 matrix = %d\n",det1,det2,det3,det4,det5,det6,det7,det8,det9,det10,det11,det12,det13,det14,det15,det16,det17,det18,det19,det20,det21,det22);
if (det1!=0||det2!=0||det3!=0||det4!=0) {
    printf("\n\n\nThe rank of the determinant is 3\n");
}
if (det_1==0&&(det5!=0||det6!=0||det7!=0||det8!=0||det9!=0||det10!=0||det11!=0||det12!=0||det13!=0||det14!=0||det15!=0||det16!=0||det17!=0||det18!=0||det19!=0||det20!=0||det21!=0||det22!=0))
{printf("\n\n\nThe rank of the matrix is 2\n");}
if (det_1==0&&(det5==0&&det6==0&&det7==0&&det8==0&&det9==0&&det10==0&&det11==0&&det12==0&&det13==0&&det14==0&&det15==0&&det16==0&&det17==0&&det18==0&&det19==0&&det20==0&&det21==0&&det22==0))
{
    printf("\n\n\nThe rank of the matrix is 1\n");
}


}

//ADDITION AND SUBTRACTION-----

void add()
{ int b[20][20],c[20][20];
    int size,ch;
    printf("\n=============================MATRIX_OPERATIONS=========================");

    //Input
    printf("\n\n\nEnter size of square matrix: ");
    scanf("%d",&size);
    printf("\nFirst matrix: ");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("Enter element a%d%d",i+1,j+1);
            printf(" : ");
            scanf("%d", &a[i][j]);
        }
    }
    printf("Second matrix: ");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("Enter element b%d%d",i+1,j+1);
            printf(" : ");
            scanf("%d", &b[i][j]);
        }
    }

    printf("\n\n=========MENU========\n1. Addition\n2. Subtract\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                { c[i][j]=a[i][j]+b[i][j];
                }
            }
            break;

        case 2:
            for(i=0;i<size;i++)
            {
                for(j=0;j<size;j++)
                { c[i][j]=a[i][j]-b[i][j];
                }
            };
            break;

        default:
            printf("\nWrong choice");
            break;
    }

    //show matrix
    printf("\n");
    for(i=0;i<size;i++)
    {   for(j=0;j<size;j++)
    {
        printf("Element c%d%d",i+1, j+1);
        printf(" : %d",c[i][j]);
        printf("\n");
    }
    }




}

//COFACTORS----


void pointer(int *x1,int *x2,int *x3,int *x4,int *x5,int *x6,int *x7,int *x8,int *x9)
{
    *x1=a[1][1]*a[2][2]-a[1][2]*a[2][1];
    *x2=-(a[1][0]*a[2][2]-a[1][2]*a[2][0]);
    *x3=a[1][0]*a[2][1]-a[1][1]*a[2][0];
    *x4=-(a[0][1]*a[2][2]-a[0][2]*a[2][1]);
    *x5=a[0][0]*a[2][2]-a[0][2]*a[2][0];
    *x6=-(a[0][0]*a[2][1]-a[0][1]*a[2][0]);
    *x7=a[0][1]*a[1][2]-a[0][2]*a[1][1];
    *x8=-(a[0][0]*a[1][2]-a[0][2]*a[1][0]);
    *x9=a[0][0]*a[1][1]-a[0][1]*a[1][0];

}

//MULTIPLICATION OF 2 3X3 MATRICES----

void multiply()
{ int m,b[3][3];
    printf("----ENter element of matrix 1----\n");
    for(i=0;i<3;i++)
    {for(j=0;j<3;j++)
    {printf("element a[%d][%d] = ",i+1,j+1);
        scanf("%d",&a[i][j]);
        c[i][j]=0;
    }
    }
    printf("----Enter element of matrix 2----\n");
    for(i=0;i<3;i++)
    {for(j=0;j<3;j++)
    {printf("element b[%d][%d] = ",i+1,j+1);
        scanf("%d",&b[i][j]);
    }
    }
    printf("\n\n---- The resultant matrix ---- \n");
    for(i=0;i<3;i++)
    {	for(j=0;j<3;j++)
    {	for(m=0;m<3;m++)
    {
        c[i][j]=c[i][j]+(a[i][m]*b[m][j]);
    }
        printf("%d  ",c[i][j]);
    }
        printf("\n");
    }



}

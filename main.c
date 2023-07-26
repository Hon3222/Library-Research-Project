#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lib{
char name[20] ;
int id ;
int num ;}book ,a ,q;

void insert(struct lib a ,struct lib array[]);
void Delete (struct lib araay[] , int i);
void linerSearch  (struct lib array[],int i ,int w );
void binarySearch(struct lib array[] , int i,struct lib q );
void sort(struct lib array[],int i,struct lib q);
void unSorted (struct lib array[] , int i );
int main()
{
struct lib array[10];
   printf("Welcome To My Library\n ");
int w ;
int i=0 ;
FILE *fptr = fopen("lib.txt" ,"r");

if (fptr==NULL )
    printf("couldn't open file");
else
       {
        fscanf(fptr,"%[^_]%*c",array[i].name);
        fscanf(fptr,"%d",&array[i].id );
        fscanf(fptr,"%d",&array[i].num);
       }

    while(!feof(fptr))
    {
        i++;
        fscanf(fptr,"%[^_]%*c",array[i].name);
        fscanf(fptr,"%d",&array[i].id );
        fscanf(fptr,"%d",&array[i].num);

    }

printf("1=Add a new book\n");
printf(" 2=Delete book \n");
printf(" 3=Search book by id \n");
printf(" 4=Search book by name \n");
printf(" 5=Display all books sorted by name \n");
printf(" 6=Display all books unsorted \n");
printf(" choose an operation\n ");
int c ;
scanf("%d",&c);

if    (c==1)
    {insert(a,array);}
else if(c==2)
      {
          Delete(array , i);
      }
else if(c==3)
    {printf("enter the id to search on the book \n ");
    scanf("%d",&w);
    linerSearch (array,i,w);}
else if(c==4)
    {binarySearch(array ,i,q );}
else if(c==5)
    {sort(array,i,q);}
else
    {unSorted( array , i);}

  int p ;
    printf("do you want to make another operation ?\n");
    printf("choose 1 to make anthor operation and -1 to end the program\n ");
    scanf("%d",&p);
    if (p==1)
        main();
    else
        return 0;
}

void insert(struct lib a ,struct lib array[] )
{
    FILE *aptr= fopen("lib.txt" ,"a");
    if (aptr==NULL)
        printf("couldn't open the file ");
    else
        printf("please enter the name.id and the quantity of your book \n ");
        getchar();
        gets(a.name);
        scanf("%d%d",&a.id,&a.num);
        fprintf(aptr ,"\n%s_ \t%d \t%d",a.name,a.id,a.num);
        fclose(aptr);

        return ;
}

void Delete (struct lib array[] , int i )
{   int  w=0 ,q ;
    printf(" please enter the ID for the book you want to delete it\n ");
    scanf("%d",&q );
    w=0; while(array[w].id !=q){ w++ ;}

    if (array[w].id != q)
        {printf(" error 404\n");}


    else
       {
        while(w<=i)
        {
            array[w]=array[w+1] ; w++ ;
        }
        i-- ;
       }

    FILE*fptr = fopen("lib.txt","w");
    for(int v=0 ;v<=i ;v++)
        fprintf(fptr ,"%s_\t %d\t %d\n " ,array[v].name ,array[v].id,array[v].num);
    fclose(fptr);

}
void linerSearch(struct lib array[] ,int i ,int w )
{
    if(array[i].id==w)
        {
            printf("%s\t %d\t %d\n",array[i].name ,array[i].id ,array[i].num );
        }
        else if (i-1>=0)
        {
            linerSearch(array,i-1 ,w);
        }

        else
            printf(" not found the book \n");


}



void binarySearch(struct lib array[] , int i,struct lib q )
 {  int y ;
    for (int pass=1 ; pass<=i ; pass ++)
    { for(y=0 ; y<=i-1 ; y++)
        {
            if (strcmp(array[y].name,array[y+1].name)>0)
                {
                  char s[10];
                  strcpy(s,array[y].name);
                  strcpy(array[y].name , array[y+1].name);
                  strcpy(array[y+1].name,s);

                  int temp ;
                  temp=array[y].id ;
                  array[y].id = array[y+1].id ;
                  array[y+1].id=temp ;

                  temp=array[y].num ;
                  array[y].num = array[y+1].num ;
                  array[y+1].num=temp ;

                }

    }
    }
char key[10] ;
int hight=i , low=0 ,middel ;
printf(" please enter the name of the book put ' _ ' in the end of the name \n");
scanf("%[^_]%*c" , key) ;


while(low <=hight)
   {
    middel=(low + hight)/2 ;
    strcmp(key,array[middel].name);
    if (strcmp(key,array[middel].name)==0)
      {printf("%s\t %d\t %d\n",array[middel].name , array[middel].id , array[middel].num);
       return ;}
    else if (strcmp(key,array[middel].name)==-1 )
        {hight=middel-1 ;}
    else
        {low = middel+1 ;}
   }
    if (array[middel].name!= key)
        printf("error 404");

return ;
 }
void sort(struct lib array[],int i,struct lib q)
{ int y ;
    for (int pass=1 ; pass<=i ; pass ++)
    {
        { for(y=0 ; y<=i-1 ; y++)

            if (strcmp(array[y].name,array[y+1].name)>0)
                {
                  char s[10];
                  strcpy(s,array[y].name);
                  strcpy(array[y].name , array[y+1].name);
                  strcpy(array[y+1].name,s);

                  int temp ;
                  temp=array[y].id ;
                  array[y].id = array[y+1].id ;
                  array[y+1].id=temp ;

                  temp=array[y].num ;
                  array[y].num = array[y+1].num ;
                  array[y+1].num=temp ;

                }
         }
    }
    for(int x=0 ; x<=i ; x++)
        printf("%s\t %d\t %d\n",array[x].name ,array[x].id ,array[x].num );

}
void unSorted( struct lib array[] , int i )
{ int x ;
    for(int x=0 ; x<=i ; x++)
        printf("%s\t %d\t %d\n",array[x].name ,array[x].id ,array[x].num );
}

#include<stdio.h>
#include<stdlib.h>
#define inf 9999
#define MAX 10
typedef struct track
{
    int drone;
    int time;
}node;
node ddist[10]={0}, djcity[10]={0};
int cost[10][10],city[10][10],fb[10][10], cost[MAX][MAX], distance[MAX], pred[MAX],dod[4]={0};
int city1[10][10],city2[10][10],city3[10][10],city14[10][10],city5[10][10],city6[10][10],city7[10][10],city7[10][10];
int fb2[10][10],fb3[10][10],fb4[10][10],fb5[10][10],fb6[10][10],fb7[10][10],fb[10][10],fb2[10][10];
int u,v,k,i,j,n,ftime[20],dtime[10];
int m=9;

int c=0;

void merge(node a[],int lbb,int mid,int ubb)
{
    int i=lbb,j=mid+1,k=lbb;
    node c[10];
    while(i<=mid && j<=ubb)
    {
        if(a[i].time<=a[j].time)
        {
            c[k]=a[i];
            i++;
        }
        else{
            c[k]=a[j];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=ubb)
        {
            c[k]=a[j];
            j++;
            k++;
        }

    }
    else if(j>ubb)
            {
               while(i<=mid)
                    {
                        c[k]=a[i];
                        i++;
                        k++;
                    }
            }
    for(k=lbb;k<=ubb;k++)
    {
        a[k]=c[k];
    }

}

void mergesort(node a[],int lbb,int ubb)
{

    int mid;
    if(lbb<ubb)
    {
        mid=(lbb+ubb-1)/2;
        mergesort(a,lbb,mid);
        mergesort(a,mid+1,ubb);
        merge(a,lbb,mid,ubb);
    }
}

void Dijkstra(int Graph[MAX][MAX], int n, int start,int location,int citynumber) {
  int  distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j,ddist[10];

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (city[i][j] == 0)
        cost[i][j] = inf;
      else
        cost[i][j] = city[i][j];


  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = inf;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start) {
            if(i==location)
            {dtime[citynumber]=distance[i];
      printf("\nTotal distance travelled by drone from source to destination ->%d= %d", i, distance[i]);
            }
    }
      printf("\n");
i=location;
if(i!=start)
{
printf("Path=%d",i);
j=i;
do
{
j=pred[j];
printf("<-%d",j);
}while(j!=start);

}
printf("\n\n");

}

void floyds (int d[10][10],int n)
{
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
          for(j=0;j<n;j++)
            {
              if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
            }
}


void town1()
{
     int source,destination,citynumber;
    printf("--------------------CITY NUMBER --->> 1--------------------\n\n\n");
	printf("\n CITY WEIGHTED MATRIX:\n");
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++)
        {
		   printf("%d \t",fb[i][j]);
        }
		printf("\n");
	}
		printf("\n\nNUMBER OF DRONE IN THE CITY =2\n\n");
	//1 st delivery.
	printf("\n\n---------THE FIRST  DELIVERY----------\n\n");
	floyds(fb,n);
	source =2;
	destination=4;
	printf("\n\n source=%d\t destination= %d",source,destination);
	for(i=0;i<2;i++)
    {
            if(dod[i]==0)
        {
        ddist[i].drone=i;
        ddist[i].time=fb[i][source];
        }
    }
    for(i=0;i<2;i++)
    {
        if(ddist[i].time==0)
            ddist[i].time=inf;
    }
    mergesort(ddist,0,1);
       for(i=0;i<2;i++)
    {
        printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist[i].drone,ddist[i].time);

    }

   ftime[c+1]= ddist[c].time;
   dod[c]=ddist[c].drone;
   printf("\ndrone on dilivery=%d\n",dod[c]);
   printf("\n drone out for source = %d,time for drone to reach the source =%d\n",ddist[c].drone,ftime[c+1]);
    citynumber =1;
    Dijkstra(city,n,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime[c+1]);
    djcity[c].time=dtime[citynumber]+ftime[c+1];
    djcity[c].drone=dod[c];
     c++;
    //2nd delivery
    printf("\n\n---------THE SECOND DELIVERY----------\n\n");
    floyds(fb,n);
   destination=3;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
  ftime[c+1]= ddist[c].time;
   dod[c]=ddist[c].drone;
    for(i=0;i<2;i++)
    {
         printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist[i].drone,ddist[i].time);

    }
     printf("\ndrone on dilivery=%d\n",dod[c]);
     printf("\ndrone id -> %d time for drone to reach the source =%d\n",ddist[c].drone,ftime[2]);
    citynumber =1;
    Dijkstra(city,n,source,destination,citynumber);
    printf("total time for dilivery 1=%d",dtime[citynumber]+ftime[c+1]);
     djcity[c].time=dtime[citynumber]+ftime[c+1];
     djcity[c].drone=dod[c];
      c++;
    /*  for(i=0;i<2;i++)
      {
          printf("\n%d\n",djcity[i].drone);
          printf("\n%d\n",djcity[i].time);
      }*/
     //3rd dilivery
     	printf("\n\n---------THE THIRD DELIVERY----------\n\n");

        floyds(fb,n);
          mergesort(djcity,0,1);
        ftime[c+1]=fb[djcity[0].drone][source];
          for(i=0;i<2;i++)
        {
            printf(" drone id ->%d and time taken by it to complete its job ->%d \n",djcity[i].drone,djcity[i].time);
        }

    destination=4;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
     printf("\ndrone id -> %d time for drone to reach the source =%d\n",djcity[0].drone,ftime[c+1]);
     citynumber =1;
    Dijkstra(city,n,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime[c+1]);
     djcity[c].time=dtime[citynumber]+ftime[c+1];
     djcity[c].drone=dod[c];
      c++;

       printf("\n\n---------------DILIVERY IN THE CITY IS OVER---------------\n\n");


}
void town2()
{
    c=0;
    int l=0,u=3;
    node ddist1[10]={0}, djcity1[10]={0};
     int ftime1[10],dod1[10]={0};
     int source,destination,citynumber;
      citynumber =2;
	printf("\n CITY WEIGHTED MATRIX:\n");
	for (i=0;i<m;i++) {
		for (j=0;j<m;j++)
        {
		   printf("%d \t",fb[i][j]);
        }
		printf("\n");
	}
		printf("number of drones in the city =4\n");
	//1 st delivery.
	printf("\n\n---------THE FIRST  DELIVERY----------\n\n");
	floyds(fb,m);
	source =4;
	destination=5;
	printf("\n\n source=%d\t destination= %d",source,destination);
	for(i=0;i<4;i++)
    {
            if(dod1[i]==0)
        {
        ddist1[i].drone=i;
        ddist1[i].time=fb[i][source];
        }
    }
    for(i=0;i<4;i++)
    {
        if(ddist1[i].time==0)
            ddist1[i].time=inf;
    }


    mergesort(ddist1,l,u);
       for(i=0;i<4;i++)
    {
        printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist1[i].drone,ddist1[i].time);

    }

   ftime1[c+1]= ddist1[c].time;
   dod1[c]=ddist1[c].drone;
   printf("\ndrone on dilivery=%d\n",dod1[c]);
   printf("\n drone out for source = %d,time for drone to reach the source =%d\n",ddist1[c].drone,ftime1[c+1]);
    Dijkstra(city,m,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime1[c+1]);
    djcity1[c].time=dtime[citynumber]+ftime1[c+1];

    djcity1[c].drone=dod1[c];
     c++;
    //2nd delivery
    printf("\n\n---------THE SECOND DELIVERY----------\n\n");
    floyds(fb,m);

    destination=3;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
  ftime1[c+1]= ddist1[c].time;
   dod1[c]=ddist1[c].drone;
    for(i=0;i<4;i++)
    {
         printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist1[i].drone,ddist1[i].time);

    }
     printf("\ndrone on dilivery=%d\n",dod1[c]);
     printf("\ndrone id -> %d time for drone to reach the source =%d\n",ddist1[c].drone,ftime1[c+1]);
    Dijkstra(city,m,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime1[c+1]);
     djcity1[c].time=dtime[citynumber]+ftime1[c+1];
     djcity1[c].drone=dod1[c];
      c++;
    /*  for(i=0;i<2;i++)
      {
          printf("\n%d\n",djcity[i].drone);
          printf("\n%d\n",djcity[i].time);
      }*/
     //3rd dilivery
     	printf("\n\n---------THE THIRD DELIVERY----------\n\n");
        floyds(fb,m);

    destination=7;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
  ftime1[c+1]= ddist1[c].time;
   dod1[c]=ddist1[c].drone;
    for(i=0;i<4;i++)
    {
         printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist1[i].drone,ddist1[i].time);

    }
     printf("\ndrone on dilivery=%d\n",dod1[c]);
     printf("\ndrone id -> %d time for drone to reach the source =%d\n",ddist1[c].drone,ftime1[c+1]);
    Dijkstra(city,m,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime1[c+1]);
     djcity1[c].time=dtime[citynumber]+ftime1[c+1];
     djcity1[c].drone=dod1[c];
      c++;

          	printf("\n\n---------THE FOURTH DELIVERY----------\n\n");
        floyds(fb,m);

    destination=6;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
  ftime1[c+1]= ddist1[c].time;
   dod1[c]=ddist1[c].drone;
    for(i=0;i<4;i++)
    {
         printf("\ndrone id=%d\t time to reach source=%d\n\n",ddist1[i].drone,ddist1[i].time);

    }
     printf("\ndrone on dilivery=%d\n",dod1[c]);
     printf("\ndrone id -> %d time for drone to reach the source =%d\n",ddist1[c].drone,ftime1[c+1]);
    Dijkstra(city,m,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime1[c+1]);
     djcity1[c].time=dtime[citynumber]+ftime1[c+1];
     djcity1[c].drone=dod1[c];
      c++;



      	printf("\n\n---------THE FIFTH DELIVERY----------\n\n");
        floyds(fb,m);
           mergesort(ddist1,l,u);
        printf("journey time for all the drones in their given job\n");
        for(i=0;i<4;i++)
        {
            printf("%d and time =%d \n",djcity1[i].drone,djcity1[i].time);
        }
        ftime1[c+1]=fb[djcity1[0].drone][source];

    destination=8;
    printf("\n\n source=%d\t destination= %d\n",source,destination);
     printf("\ndrone id that will go to the job-> %d time for drone to reach the source =%d\n",djcity1[0].drone,ftime1[c+1]);
    Dijkstra(city,m,source,destination,citynumber);
    printf("total time for dilivery =%d",dtime[citynumber]+ftime1[c+1]);
     djcity1[c].time=dtime[citynumber]+ftime1[c+1];
     djcity1[c].drone=dod1[c];
      c++;
      printf("\n\n---------------DILIVERY IN THE CITY IS OVER---------------\n\n");




}




int main()
{
int up=20,lb=10;;
n=5;

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
       // printf("enter the weight of the node %d and %d\n",i,j);
        if(i<j)
        {
        city[i][j]=(rand() %(up-lb+1)) +lb;
       // printf("%d\n",city[i][j]);
        }
       else if(i==j)
        city[i][j]=0;
        else if(j<i)
            city[i][j]=city[j][i];
            else if(cost[i][j]==0)
                cost[i][j]=inf;



    }
}

for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
       fb[i][j]=city[i][j];
       printf("%d\t",city[i][j]);
    }
    printf("\n");
}
town1();

printf("\n\n");
for(i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        //printf("enter the weight of the node %d and %d\n",i,j);
        if(i<j)
        {
        city[i][j]=(rand() %(up-lb+1)) +lb;
       // printf("%d\n",city[i][j]);
        }
       else if(i==j)
        city[i][j]=0;
        else if(j<i)
            city[i][j]=city[j][i];
            else if(cost[i][j]==0)
                cost[i][j]=inf;
    }
}
for(i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
       fb[i][j]=city[i][j];
       printf("%d\t",city[i][j]);
    }
    printf("\n");
}
printf("\n--------------------CITY NUMBER --->> 2--------------------\n\n\n");
town2();
printf("\n\n");
for(i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        //printf("enter the weight of the node %d and %d\n",i,j);
        if(i<j)
        {
            lb=200;
            up=300;
        city[i][j]=(rand() %(up-lb+1)) +lb;
       // printf("%d\n",city[i][j]);
        }
       else if(i==j)
        city[i][j]=0;
        else if(j<i)
            city[i][j]=city[j][i];
            else if(cost[i][j]==0)
                cost[i][j]=inf;
    }
}
printf("\n--------------------CITY NUMBER --->> 3--------------------\n\n\n");
town2();
printf("\n\n");
for(i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        //printf("enter the weight of the node %d and %d\n",i,j);
        if(i<j)
        {
            lb=1000;
            up=2500;
        city[i][j]=(rand() %(up-lb+1)) +lb;
       // printf("%d\n",city[i][j]);
        }
       else if(i==j)
        city[i][j]=0;
        else if(j<i)
            city[i][j]=city[j][i];
            else if(cost[i][j]==0)
                cost[i][j]=inf;
    }
}
printf("--------------------CITY NUMBER --->> 4--------------------\n\n\n");
town2();
printf("\n\n");
for(i=0;i<m;i++)
{
    for(j=0;j<m;j++)
    {
        //printf("enter the weight of the node %d and %d\n",i,j);
        if(i<j)
        {
            lb=30;
            up=56;
        city[i][j]=(rand() %(up-lb+1)) +lb;
       // printf("%d\n",city[i][j]);
        }
       else if(i==j)
        city[i][j]=0;
        else if(j<i)
            city[i][j]=city[j][i];
            else if(cost[i][j]==0)
                cost[i][j]=inf;
    }
}
printf("--------------------CITY NUMBER --->> 5--------------------\n\n\n");
town2();


     }
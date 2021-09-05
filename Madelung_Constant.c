#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//(face centered cubic, sodium chloride)
double entry(int i, int j, int k);
double facet(int i, int j, int k, int control);
double madelung(int control);
int main (){
      int dec=0;
      int control=1;
      int container=0;
      double realdiff=0;
      double difference=0;
      double result=0;
      double times=1;
      double reference=0;
      printf("This program helps you calculate the Madelung Constant. Please enter the precision you need:\n (maximum:10e-1  minimum:10e-9)\n");
      scanf("%d",&dec);
      times=pow(10,dec);
      realdiff=1.0/times;
      difference=madelung(control+1)-madelung(control);
      while(difference>=realdiff){
            control++;
            difference=madelung(control+1)-madelung(control);
      }
      control++;
      result=madelung(control);
      result*=times;
      reference=result;
      container=result;
      result=container;
      reference=(reference-result)*10;
      if(reference>=5){
            result++;
      }
      result/=times;
      //result=madelung(8);
      printf("The result is %f .\nIf you would like to improve the precision, you may input a larger number next time.\n",result);
      printf("\n");
      return 0;
}
double madelung(int control)
{
      int i=0;
      int j=0;
      int k=0;
      double sum=0;
      for(i=-control;i<(control+1);i++){
            for(j=-control;j<(control+1);j++){
                  for(k=-control;k<(control+1);k++){
                        sum+=facet(i,j,k,control)*entry(i,j,k);
                  }
            }
      }
      return sum;
}
double entry(int i, int j, int k)
{
      int jud=i+j+k;
      int sumul=i*i+j*j+k*k;
      double entry=0;
      double core=1.0/(sqrt(1.0*(sumul)));
      if(sumul!=0){
                  if(jud%2==0){
                        entry=-core;
                  }
                  else {
                        entry=core;
                  }
      }
      else{
            entry=0;
      }
      return entry;
}
double facet(int i, int j, int k, int control)
{
      double facet=0;
      int cnt=0;
      if(i==control||-i==control){
            cnt++;
      }
      if(j==control||-j==control){
            cnt++;
      }
      if(k==control||-k==control){
            cnt++;
      }
      if(cnt==0){
            facet=1;
      }
      if(cnt==1){
            facet=0.5;
      }
      if(cnt==2){
            facet=0.25;
      }
      if(cnt==3){
            facet=1.0/8;
      }
      return facet;
}

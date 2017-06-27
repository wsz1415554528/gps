#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char time[10],gps,latitude1,longitude1,year[10],s[5],latitude[10],longitude[10];
    double v,course;
    FILE *fp2,*fp1,*fp3;
    char Time[10],Latitude1,Longitude1,moon[10],S[5],altitude[10];
    double Latitude,Longitude;
    int Gps;
    fp1=fopen("//Users//w20161104602//Desktop//gps//gps.txt","w+");
    fp2=fopen("//Users//w20161104602//Desktop//gps//GPS170510.log","r");
    fp3=fopen("//Users//w20161104602//Desktop//gps//gps.csv","w+");
    if(fp2==NULL)
    {
        printf("打开文件错误，要打开的文件可能不存在");
    }
    else
    {
        while(fscanf(fp2,"$GPRMC,%6s,%c,%8s,%c,%9s,%c,%lf,%lf,%6s,,%3s\n$GPGGA,%6s,%lf,%c,%lf,%c,%d,%2s,,%4s,M,,M,,%3s\n",time,&gps,latitude,&latitude1,longitude,&longitude1,&v,&course,year,s,Time,&Latitude,&Latitude1,&Longitude,&Longitude1,&Gps,moon,altitude,S)!=EOF)
        {
            if(gps=='A')
            {
                fprintf(fp1,"当前是%c%c年%c%c月%c%c日%c%c时%c%c分%c%c秒\n",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                printf("当前是%c%c年%c%c月%c%c日%c%c时%c%c分%c%c秒\n",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                fprintf(fp3,"%c%c年%c%c月%c%c日,%c%c时%c%c分%c%c秒,",year[4],year[5],year[2],year[3],year[0],year[1],time[0],time[1]+8,time[2],time[3],time[4],time[5]);
                if(latitude1=='N')
                {
                    fprintf(fp1,"该车位于北纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    printf("该车位于北纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    fprintf(fp3,"北纬%c%c度%c%c%c%c%c分,",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                }
                else
                {
                    fprintf(fp1,"该车位于南纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    printf("该车位于南纬%c%c度%c%c%c%c%c分\n",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                    fprintf(fp3,"南纬%c%c度%c%c%c%c%c分,",latitude[0],latitude[1],latitude[2],latitude[3],latitude[5],latitude[6],latitude[7]);
                }
                if(longitude1=='E')
                {
                    fprintf(fp1,"该车位于东经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    printf("该车位于东经%c%c%c度%c%c%c%c分\n",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                    fprintf(fp3,"东经%c%c%c度%c%c%c%c分,",longitude[0],longitude[1],longitude[2],longitude[3],longitude[4],longitude[6],longitude[7]);
                }

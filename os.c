#include<stdio.h> 


void rr (int no ,int remTime [10],int Cur_t ,int arT [10], int burstTime [10]);

main() 
{
	int pno ,j, no ,curTime , RemProc , flag ,timeQ ,wait , TAT , arT[10] , burstTime[10] , remTime[10] , x =1 ;
	flag = 0;
	wait = 0;
	TAT = 0;
	printf("Enter how many number of process you want to execute "); 
	scanf("%d",&no);
	RemProc = no;
	
	printf("\nEnter \n 1. arrival time \n 2.burst time of the processes\n");
	for(pno = 0;pno < no;pno++) 
	{
		printf("\nProcess P%d\n",pno+1);
		printf("Arrival time = "); 
		scanf("%d",&arT[pno]);
		printf("Burst time = "); 
		scanf("%d",&burstTime[pno]); 
		remTime[pno]=burstTime[pno]; 
	} 
	 
	timeQ=3;
	curTime=0;
	for(pno=0;RemProc!=0;) 
	{
		if(remTime[pno]<=timeQ && remTime[pno]>0)
		{ 
			curTime+=remTime[pno];
			remTime[pno]=0; 
			flag=1; 
		} 
		else if(remTime[pno]>0)
		{ 
			remTime[pno]-=timeQ; 
			curTime+=timeQ; 
		} 
		if(remTime[pno]==0 && flag==1)			
		{ 
			RemProc--;				
			
			wait+=curTime-arT[pno]-burstTime[pno]; 
			TAT+=curTime-arT[pno]; 
			flag=0; 
                       
		} 
		if(pno==no-1){
			x++;
			if(x==2){
				pno=0;
				timeQ=6;
				
				
			}
			else{
				break;
			}
		}
		else if(curTime >= arT[pno+1]){
			pno++;
		}
		else{
			pno=0;
		}
	}
	
	rr(no,remTime,curTime,arT,burstTime);
	
	return 0;
}


void rr(int no,int remTime[10],int Cur_t,int arT[10], int burstTime[10]){
	
	float avg_wait,avg_TAT;
    int i,j,n=no,temp,btime[20],pno[20],w_time[20],TAT_t[20],total=0,loc;
    
   
    
    for(i=0;i<n;i++)
    {
        btime[i]=remTime[i];
        w_time[i]=Cur_t-arT[i]-btime[i];
		pno[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=pno[i];
        pno[i]=pno[loc];
        pno[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	w_time[i]+=btime[j];
        }
        total+=w_time[i];
    }
 
    avg_wait=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\twaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        TAT_t[i]=btime[i]+w_time[i];
        total=total + TAT_t[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",pno[i],btime[i],w_time[i],TAT_t[i]);
    }
    avg_TAT=(float)total/n;
    printf("\n\nAverage waiting time = %f",avg_wait);
    printf("\n Average turnaround time = %f\n",avg_TAT);
	
}



#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;


//knapsack code 

int max(int a, int b) { return (a > b) ? a : b; }

void knapSack(int W, int wt[], int val[], int n,float prot_need,string ITEMS[])
{
    int i, w;
     
      float K[n+1][W+1];
 
    // Build table K[][] in bottom up manner
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    
    int p=W;
        int i_cord=n;
      
        
    for(int x=0;x<=n;x++)
    {
        
        
           if(prot_need<K[x][W])
        {
            i_cord=x;
            break;
        }     
        
    }
    
    int soln_arr[n];
    for(int ini=0;ini<n;ini++)
    soln_arr[ini]=0;
    
    
    int I=i_cord;
    int WT=W;
    int cell=K[I][WT];
    
    while (I>=0&&WT>=0)
    {
        
        if (cell != K[I-1][WT]) {
 
           soln_arr[I-1]=1; 
          
            cell=cell -val[I-1];
            WT=WT-wt[I-1];
          
        }
        else
        soln_arr[I-1]=0;
 
        I=I-1;
    }
    
    
    
    int sol_cal=0;
    int sol_prt=0;
    int c=1;
    for(int xz=0;xz<n;xz++)
    {
        
      if(soln_arr[xz]==1)
       {
           
           sol_cal=sol_cal+wt[xz];
           sol_prt=sol_prt+val[xz];
           cout<<c<<" "<<ITEMS[xz]<<endl; 
           c++;
       }
       
        
    }
    cout<<endl;
    cout<<"    Total calories in this diet :"<<sol_cal<<endl<<"    Total protein in this diet  :"<<sol_prt<<endl<<endl<<"         Enjoy your meal plan!"<<endl<<endl<<".........................................Thank you!..................................";
   
   
  
    
    
    
    
    
}







float ppg_decider(int lifeType,float bmi)
{
    
    int choice;
    float ppg;
    if(bmi>25)
{
    cout<<"      you are Overweight"<<endl<<endl<<"      Suggested action would be Fat loss"<<endl<<endl<<"      enter 1 for maintainance"<<endl<<"            2 for muscle gain"<<endl<<"            3 for fat loss      ";
cin>>choice;
{
if((choice==1)&&(lifeType=1))
ppg=1.2;
else if((choice==2)&&(lifeType=1))
ppg=1.8;
else if((choice==3)&&(lifeType=1))
ppg=1.5;
else if((choice==1)&&(lifeType=2))
ppg=1.7;
else if((choice==2)&&(lifeType=2))
ppg=2.1;
else if((choice==3)&&(lifeType=2))
ppg=1.4;
}
    
}  
else if(bmi<25 && bmi>18.5)
  {
    cout<<"      you have optimal weight "<<endl<<endl<<"      Suggested action would be maintainance or muscle gain"<<endl<<endl<<"      enter 1 for maintainance"<<endl<<"            2 for muscle gain"<<endl<<"            3 for fat loss      ";
    cin>>choice;
    {
    if((choice==1)&&(lifeType=1))
ppg=1.3;
else if((choice==2)&&(lifeType=1))
ppg=1.65;
else if((choice==3)&&(lifeType=1))
ppg=1.35;
else if((choice==1)&&(lifeType=2))
ppg=1.7;
else if((choice==2)&&(lifeType=2))
ppg=2.1;
else if((choice==3)&&(lifeType=2))
ppg=1.5;
    }
  }  
    
    
else
{
    cout<<"      you are underweight"<<endl<<endl<<"      Suggested action would be muscle gain"<<endl<<endl<<"      enter 1 for maintainance"<<endl<<"            2 for muscle gain"<<endl<<"            3 for fat loss      ";
    cin>>choice;
  {  
    if((choice==1)&&(lifeType=1))
ppg=1.2;
else if((choice==2)&&(lifeType=1))
ppg=1.8;
else if((choice==3)&&(lifeType=1))
ppg=1.35;
else if((choice==1)&&(lifeType=2))
ppg=1.7;
else if((choice==2)&&(lifeType=2))
ppg=2.15;
else if((choice==3)&&(lifeType=2))
ppg=1.35;
}
    
}

return ppg;
}


int main() {
    
    
int LIFEtype;


cout<<"      enter 1 for sedentary lifestyle"<<endl<<"            2 for active lifestyle"<<endl;
cin>>LIFEtype;
cout<<endl<<endl;



float wt;
cout<<"      enter your weight in kgs : ";
cin>>wt;
cout<<endl;
float hti;
cout<<"      enter your height in inches : ";
cin>>hti;
cout<<endl<<endl;
float htm=hti*0.0254;    
 
     float BMI=(wt)/(htm*htm);
cout<<"      Your BMI is : "<<BMI<<endl;
 

 float PPG=ppg_decider(LIFEtype,BMI);


float protein_intake=wt*PPG;
cout<<endl<<endl;
cout<<"      Your protein intake should be  :"<<protein_intake<<endl<<endl;



int protein_content[23] = {4,1,3,8,1,7,1,3,23,8,9,9,1,22,22,17,5,5,25,1,9,4,21 };
   int calorie[23] = {113,95,31,357,110,75,359,130,100,149,207,256,500,206,336,389,138,131,402,26,116,77,58 };
   
   int max_cal = 2000;
  string items[23] = { "chapati", "apple","sprouts", "cornflakes","banana","egg","dry fruits","rice","meat","milk","peanut_butter","bread","normal_butter","fish","salami","oats","noodles","pasta","cheese","pumpkin","lentils","potato","sun flower seeds"  };
   int n = 23;
   
   cout<<endl;
   
   cout<<"Finding the best diet for you............"<<endl<<endl;
   cout<<"Your meal plan for the day is------->"<<endl<<endl;
   
   knapSack(max_cal, calorie,protein_content,n,protein_intake,items);




    return 0;
}


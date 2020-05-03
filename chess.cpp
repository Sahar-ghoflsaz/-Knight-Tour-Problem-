#include <iostream>
#include<math.h>
using namespace std;
class shatranj
{
public:
        int count;
        int * col;
        int * en;
        int n;
        int countQ;
        int countH;
        int existence;
        int kol;
        int omid_bakhsh;
        shatranj(int n){
            count=0;
                countH=0;
                countQ=0;
                this->n=n;
                kol=0;
                omid_bakhsh=0;
                existence = 0;
                col= new int [n+1];
                en= new int [n+1];


        }
        void show()
{
          for(int i=1 ; i<=n ; i++){
              for(int j=1 ; j<=n ; j++){
                  if(col[i]==j){
                      if(en[i]== 1 )
                            cout<<"Q\t";
                      else
                            cout<<"H\t";
                  }
                  else{
                      cout<<"-\t";
                  }
              }
              cout<<endl;
          }
          count++;
          cout<<"----------------------------------------------------------\n";
          cout<<count<<endl;


}
        void solve(int i)
        {
                if(promising(i))
                {
                        if(i == n)
                        {
                                show();
                                count++;
                                existence = 1;
                        }
                        else
                        {
                                for(int j=1;j<=n;j++)
                                {
                                        col[i+1]=j;
                                        en[i+1]=1;//queen
                                        countQ++;
                                        solve(i+1);
                                        countQ--;
                                        countH++;
                                        en[i+1]=0;//horse
                                        solve(i+1);
                                        countH--;

                                }

                        }


                }
        }

        bool promising(int i)
        {
                int k=1;
                bool swich= true;
                if( i==0 )
                        return swich;
                int mid;
                if ((n%2) )
                {
                        mid = n/2+1;
                }
                else{
                        mid = n/2;
                }
                if(countH > mid || countQ > mid )
                        return false;


                while(k<i && swich)
                {
                        if(en[i]==1 &&en[k]==1 ) // queen queen
                        {
                            if(col[i] == col[k] || fabs(col[i]-col[k])==(i-k) )
                            {
                                    swich= false;
                            }
                        }
                        else if(en[k]==0 &&en[i]==0 )//horse horse
                        {
                            if( (i - k) == 2)
                            {
                                    if( fabs(col[k] -col[i] )==1  )
                                            swich= false;
                            }
                            else if( (i - k) == 1)
                            {
                                    if(fabs(col [k]-col[i])==2  )
                                            swich= false;
                            }

                        }
                        else if((en[k]==1 &&en[i]==0)|| (en[k]==0 &&en[i]==1) )// queen && horse
                        {

                            //bool tst = true;
                            if(col[i] == col[k] || fabs(col[i]-col[k])==(i-k) )
                            {
                                    swich= false;
                            }
                            if(swich)
                                if( (i - k) == 2)
                                {
                                        if( fabs(col[k] -col[i] )==1  )
                                                swich= false;
                                }
                                else if( (i - k) == 1)
                                {
                                        if(fabs(col [k]-col[i])==2  )
                                                swich= false;
                                }




                        }
                        k++;

                }

                kol++;
                if(swich)
                        omid_bakhsh++;
                return swich;

        }

};


int main()
{
        int n;
        cout<<"enter n :";
        cin>>n;
        shatranj chess(n);
        chess.solve(0);
        cout<<chess.count;
        if( ! chess.existence )
                cout<<"no way"<<endl;
        cout<<"tedad gereh haye kol :"<<chess.kol<<endl;
        cout<<"tedad gereh haye omid bakhsh :"<<chess.omid_bakhsh<<endl;

}

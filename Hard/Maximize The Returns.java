class Solution
{
    //90/100 tc passed
    static void helper2( int data[], int start, int end, int pos, int k,int []nac,int d,int marks, int returns[])
    {

        if ( k == pos)
        {


            int m[] =new int[end+1];

            int num = 0;
            for(int i=0;i<=end;i++)
                m[i]=1;


            for(int i=0;i<k;i++)
            {
                m[data[i]]=0;
                for(int j=1;j<=d && j<=end-data[i];j++)
                    m[data[i]+j]=marks;
            }

            //find temp total return
            for(int i=0;i<=end;i++)
                num+=returns[i]*m[i];


            if(num>nac[0])
                nac[0]=num;

            return;
        }

        //recursive to find combination
        for(int i = start; end>=i && k-pos<=end-i+1; i++)
        {
            data[pos]=i;
                helper2(data,i+1,end,pos+1,k,nac,d,marks, returns);//Recursive call
        }
    }


    static void helper1(int n, int k, int d, int m, int returns[],int []nac){
        int ans[] =new int[k];
        helper2( ans, 0, n-1, 0, k, nac, d, m, returns);
    }




    static int  calculateMaximizedReturns(int n, int k, int d, int m, int returns[])
    {
        int i=0;
        int max =Integer.MIN_VALUE;
        int nac[] = new int[1];
        for (i=0;i<=k;i++)
        {
            helper1( n , i , d , m , returns , nac);
            max = (nac[0] > max) ? nac[0] : max ;
        }
        return max;
    }
  //Main Method yahan par
}

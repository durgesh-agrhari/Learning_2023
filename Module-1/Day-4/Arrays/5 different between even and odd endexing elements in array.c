    #include <stdio.h>

    int main()
    {
        int n;
        printf("Enter size of the array : ");
        scanf("%d",&n);
        
        int arr[n];
        printf("Enter elements in array : ");
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        
        int sumeven =0, sumodd=0;
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                sumeven = sumeven + arr[i];
            }
            else if(i%2!=0)
            {
                 sumodd = sumodd + arr[i];
            }
        }
        
        printf("\n sum of even indexed elements = ");
        for(int i=0; i<n; i++)
        {
            
            if(i%2==0)
            {
                printf("%d", arr[i]);
                printf("+");
            }
            
        }
        printf("\n Total sum of even indexed elements %d \n", sumeven);

        printf("\n sum of odd indexed elements = ");
        for(int i=0; i<n; i++)
        {
            
            if(i%2!=0)
            {
                printf("%d",arr[i]);
                printf("+");
            }
        }
        
        printf("\n Total sum of odd indexed elements %d \n", sumodd);

        return 0;
        
    }
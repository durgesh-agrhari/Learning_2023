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
            if(arr[i]%2==0)
            {
                sumeven = sumeven + arr[i];
            }
            else if(arr[i]%2!=0)
            {
            sumodd = sumodd + arr[i];
            }
        }
        
        printf("\n sum of even elements = ");
        for(int i=0; i<n; i++)
        {
            
            if(arr[i]%2==0)
            {
                printf("%d", arr[i]);
                printf("+");
            }
            
        }
        printf("\n Total sum of even elements %d \n", sumeven);

        printf("\n sum of odd elements = ");
        for(int i=0; i<n; i++)
        {
            
            if(arr[i]%2 !=0)
            {
                printf("%d", arr[i]);
                printf("+");
            }
        }
        
        printf("\n Total sum of odd elements %d \n", sumodd);

        return 0;
        
    }
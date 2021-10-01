#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Activity
{
    char ID;
    unsigned int start;
    unsigned int end;
};

int main()
{
    vector<Activity*> arr;
    int n;
    cout<<"n: ";
    cin>>n;
    Activity *ptr;
    printf("ID  Start   End\n");
    for(int i=0; i<n; i++)
    {
        ptr = new Activity;
        cin>>ptr->ID>>ptr->start>>ptr->end;
        arr.push_back(ptr);
    }
    sort(arr.begin(), arr.end(), [](Activity *a, Activity *b){return (a->end < b->end);});
    printf("Sorted Activities\n");
    printf("ID  Start   End\n");
    for(auto x : arr)
        cout<<x->ID<<"  "<<x->start<<"  "<<x->end<<'\n';
    int take = 1;
    int end = arr[0]->end;
    printf("Activity Selected:\n");
    printf("ID  Start   End\n");
    printf("%c  %d  %d\n", arr[0]->ID, arr[0]->start, arr[0]->end);
    for(int i=1; i<n; i++)
    {
        if(arr[i]->start >= end)
        {
            printf("%c  %d  %d\n", arr[i]->ID, arr[i]->start, arr[i]->end);
            take++;
            end = arr[i]->end;
        }
    }
    cout<<take<<'\n';
    return 0;
}
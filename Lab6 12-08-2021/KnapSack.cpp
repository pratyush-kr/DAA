#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>

int RandomProfit()
{
    return rand() % 15 + 1;
}

int RandomWeight()
{
    return rand() % 25 + 1;
}

class Object
{
    public:
        std::string obname;
        float profit;
        float weight;
        float pbyw;
        float parts;
        Object()
        {
            static int x;
            std::string num = (std::string)std::to_string(++x);
            obname = "O" + num;
            profit = RandomProfit();
            weight = RandomWeight();
            pbyw = profit/weight;
            parts = 1;
        }
        void show()
        {
            printf("%-4s %-6.2f %-4.2f   %-7.2f %-8.2f\n",&obname[0], profit, pbyw, parts, weight);
        }
};

int comparePbyW(const Object &a, const Object &b)
{
    return (a.pbyw > b.pbyw)? 1:0;
}

int compareP(const Object &a, const Object &b)
{
    return (a.profit > b.profit)? 1:0;
}

int compareW(const Object &a, const Object &b)
{
    return (a.weight > b.weight)? 1:0;
}

int main()
{
    std::vector<Object*> KnapSack;
    int total, capacity;
    std::cout<<"Total Objects: ";
    std::cin>>total;
    srand(time(0));
    Object objects[total];
    float weight;
    std::cout<<"Total Weight Knapsack can hold: ";
    std::cin>>weight;
    std::cout<<"Capacity: ";
    std::cin>>capacity;
    std::sort(&objects[0], &objects[total-1], comparePbyW);
    printf("Objects\n");
    printf("Name Profit PbyW   Parts Weights\n");
    for(int i=0; i<total; i++)
        objects[i].show();
    std::cout<<"\n";
    std::queue<Object*> Queue;
    for(int i=0; i<total; i++)
        Queue.push(&objects[i]);
    while(weight != 0 && capacity--)
    {
        if(Queue.front()->weight < weight)
        {
            Object *ptr = Queue.front();
            KnapSack.push_back(ptr);
            weight -= ptr->weight;
            Queue.pop();
        }
        else
        {
            Object *ptr = Queue.front();
            float factor = ptr->weight/weight;
            ptr->weight = ptr->weight/factor;
            ptr->parts = ptr->parts/factor;
            ptr->profit = ptr->profit/factor;
            KnapSack.push_back(ptr);
            Queue.pop();
            weight = 0;
        }
    }
    float p = 0,w=0,x=0;
    printf("Knapsack: \n");
    printf("Name Profit PbyW   Parts Weights\n");
    for(int i=0; i<KnapSack.size(); i++)
    {
        p += KnapSack[i]->profit;
        w += KnapSack[i]->weight;
        KnapSack[i]->show();
    }
    printf("Total Profit = %.2f\nTotal Weight = %.2f\nObjects = %ld\n", p, w, KnapSack.size());
}
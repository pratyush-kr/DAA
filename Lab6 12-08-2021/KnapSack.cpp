#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

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
        float profit;
        float weight;
        float pbyw;
        float parts;
        Object()
        {
            profit = RandomProfit();
            weight = RandomWeight();
            pbyw = profit/weight;
            parts = 1;
        }
        void show()
        {
            printf("%-6.0f %-4.2f   %-7.2f %-8.0f\n", profit, pbyw, parts, weight);
        }
};

int compare(const Object &a, const Object &b)
{
    return (a.pbyw > b.pbyw)? 1:0;
}

int main()
{
    std::vector<Object*> KnapSack;
    int total;
    std::cout<<"Total Objects: ";
    std::cin>>total;
    srand(time(0));
    Object objects[total];
    float weight;
    std::cout<<"Total Weight Knapsack can hold: ";
    std::cin>>weight;
    std::sort(&objects[0], &objects[total-1], compare);
    printf("Profit PbyW   Parts Weights\n");
    for(int i=0; i<total; i++)
        objects[i].show();
    std::queue<Object*> Queue;
    for(int i=0; i<total; i++)
        Queue.push(&objects[i]);
    int i=0;
    while(weight != 0)
    {
        if(objects[i].weight < weight)
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
            ptr->weight = ptr->weight/factor;
            ptr->profit = ptr->profit/factor;
            KnapSack.push_back(ptr);
            Queue.pop();
            weight = 0;
        }
    }
    printf("Knapsack: \n");
    printf("Profit PbyW   Parts Weights\n");
    for(int i=0; i<KnapSack.size(); i++)
        KnapSack[i]->show();
}
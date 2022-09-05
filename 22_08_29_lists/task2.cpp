// Node Definition

struct Node
{
    Node *next;
    int data;
};

int Length(Node *head)
{
    int len = 0;
    while (head)
    {
        ++len;
        head = head->next;
    }
    return len;
}

int Count(Node *head, int data)
{
    int cnt = 0;
    while (head)
    {
        if (head->data == data)
        {
            ++cnt;
        }
        head = head->next;
    }
    return cnt;
}
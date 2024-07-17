/* 
The structure of the class is
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
 */

//Function to push an element x in a queue.
void MyQueue :: push(int x)
{
    arr[rear] = x; 
    rear++;
    if(rear >= 100005) rear = rear%100005;
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop()
{
    if(front == rear) return -1;
    int val = arr[front];
    front++;
    return val;
}
int pop(vector<int> &heap)
{
    int n = heap.size();
    if(n==0) return -1;

    int ans= heap[0];
    swap(heap[0],heap[n-1]);
    auto it = heap.end();
    heap.erase(it-1);

    int i=0;
    int size = heap.size();
    while(i<size)
    {
        int left = 2*i;
        int right = 2*i+1;
        if(left<size && right<size && heap[left]>= heap[right] &&  heap[i]<heap[left])
        {
            swap(heap[left],heap[i]);
            i = left;
        }
        else if (right<size && heap[right]>heap[i])
        {
            swap(heap[right],heap[i]);
            i = right;    
        }
        else break;
    }
    return ans;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }

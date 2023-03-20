#include <stdio.h>
  //Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
  struct Node* copyRandomList(struct Node* head)
{
      //1.在每个结点的后面生成拷贝结点
      struct Node* cur = head;
      while (cur)
      {
          struct Node* next = cur->next;
          struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
          copy->val = cur->val;
          //cur  copy  next
          cur->next = copy;
          copy->next = next;
          //插入结点
          // 迭代
          cur = next;
       }
       //2.处理每个拷贝结点的random
      cur = head;
      while (cur)
      {
          struct Node* copy = cur->next;
          if (cur->random == NULL)
          {
              copy->random = NULL;
          }
          else
          {
              copy->random = cur->random->next;
          }
          cur = cur->next->next;
      }
      //3.解下拷贝结点，恢复原来结点链接
      cur = head;
      struct Node* copyhead = NULL, * tail = NULL;
      while (cur)
      {
          //解下拷贝结点就是把结点拿下来尾插.尾插需要头指针尾指针
          struct Node* copy = cur->next;
          struct Node* next = copy->next;
          if (copyhead == NULL)
          {
              copyhead = tail = copy;
          }
          else
          {
              tail->next = copy;
              tail = tail->next;
          }
          //恢复链接关系
          cur->next = next;

          //迭代
          cur = next;
      }
      return copyhead;
}
  //因为队列要求在队尾入数据
  //队头出数据，使用链表就需要找尾
  //    而队列的各种功能比如入队，计算大小，等
  //    需要传头位置和尾部位置，所以为了简化我们再定义一个结构体将头位置与尾指针分装起来，
  //也就是有多个数据就使用结构体分装起来，那只要传个结构体就可以了，不需要传多个数据过去
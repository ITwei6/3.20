#include <stdio.h>
  //Definition for a Node.
  struct Node {
      int val;
      struct Node *next;
      struct Node *random;
  };
  struct Node* copyRandomList(struct Node* head)
{
      //1.��ÿ�����ĺ������ɿ������
      struct Node* cur = head;
      while (cur)
      {
          struct Node* next = cur->next;
          struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
          copy->val = cur->val;
          //cur  copy  next
          cur->next = copy;
          copy->next = next;
          //������
          // ����
          cur = next;
       }
       //2.����ÿ����������random
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
      //3.���¿�����㣬�ָ�ԭ���������
      cur = head;
      struct Node* copyhead = NULL, * tail = NULL;
      while (cur)
      {
          //���¿��������ǰѽ��������β��.β����Ҫͷָ��βָ��
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
          //�ָ����ӹ�ϵ
          cur->next = next;

          //����
          cur = next;
      }
      return copyhead;
}
  //��Ϊ����Ҫ���ڶ�β������
  //��ͷ�����ݣ�ʹ���������Ҫ��β
  //    �����еĸ��ֹ��ܱ�����ӣ������С����
  //    ��Ҫ��ͷλ�ú�β��λ�ã�����Ϊ�˼������ٶ���һ���ṹ�彫ͷλ����βָ���װ������
  //Ҳ�����ж�����ݾ�ʹ�ýṹ���װ��������ֻҪ�����ṹ��Ϳ����ˣ�����Ҫ��������ݹ�ȥ
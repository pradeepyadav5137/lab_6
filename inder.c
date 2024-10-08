// #include <stdio.h>
// #include <conio.h>
// #include <stdlib.h>

// #include <string.h>

// struct stak
// {
//     int op;
//     struct node *ud_node;
//     struct stak *next;
// };

// struct stak *create_node_stk(struct node *a, int op)
// {
//     struct stak *new_address = (struct stak *)malloc(sizeof(struct stak));

//     // scanf("%d", &(*new_address).datum);
//     (*new_address).ud_node = a;
//     (*new_address).op = op;
//     (*new_address).next = NULL;
//     return new_address;
// }

// int isempty(struct stak *head)
// {
//     if (head == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void push(struct stak **start, struct node *a, int op)
// {
//     struct stak *new = create_node_stk(a, op);
//     new->next = *start;
//     *start = new;
// }

// struct stak *pop(struct stak **start)
// {
//     struct stak *temp = *start;

//     if (!isempty(*start))
//     {
//         start = (*start).next;

//         return temp;
//     }
//     else
//     {
//         return temp;
//     }
// }

// struct node
// {
//     int P_id;
//     char name[20];
//     int price;
//     struct node *next;
// };

// struct node *create_node_cart()
// {
//     struct node *node_address = (struct node *)malloc(sizeof(struct node));

//     (*node_address).next = NULL;

//     printf("\nEnter product id : ");
//     scanf("%d", &(*node_address).P_id);

//     printf("\nEnter product name : ");
//     scanf("%s", (*node_address).name);

//     printf("\nEnter product price : ");
//     scanf("%d", &(*node_address).price);

//     return node_address;
// }

// struct node *insert_item(struct node **start)
// {
//     struct node *new = create_node_cart();
//     new->next = *start;
//     *start = new;
//     return new;
// }

// void display(struct node *start)
// {
//     struct node *current = start;
//     if (start != NULL)
//     {
//         printf("\n\tProduct ID\tProduct name\tProduct price");
//         while (current != NULL)
//         {
//             printf("\n\t%d\t\t%s\t\t%d", (*current).P_id, (*current).name, (*current).price);
//             current = (*current).next;
//         }
//     }
//     else
//     {
//         printf("\nCart is empty.");
//     }
// }

// struct node *delete_node(struct node **start)
// {

//     int id;
//     struct node *current = *start, *temp;
//     if (*start == NULL)
//     {
//         printf("\nCart is empty.");
//         return current;
//     }
//     printf("\nEnter the Product ID you want to delete : ");
//     scanf("%d", &id);
//     if ((**start).P_id == id)
//     {
//         printf("\n\tRemoved successfully....\n\tProduct ID\tProduct name\tProduct price");
//         printf("\n\t%d\t\t%s\t\t%d", (*current).P_id, (*current).name, (*current).price);
//         temp = current;
//         start = (*start).next;

//         return temp;
//     }
//     else
//     {
//         while ((*current).next != NULL && (*current).next->P_id != id)
//         {
//             current = (*current).next;
//         }
//         if ((*current).next == NULL)
//         {
//             printf("\nNo such data to delete.");
//             return (*current).next;
//         }
//         else
//         {
//             printf("\n\tRemoved successfully....\n\tProduct ID\tProduct name\tProduct price");
//             printf("\n\t%d\t\t%s\t\t%d", (*current).next->P_id, (*current).next->name, (*current).next->price);
//             temp = (*current).next;
//             (*current).next = (*current).next->next;

//             return temp;
//         }
//     }
// }

// void undo(struct node **start, struct stak **s, struct node *undonode, int ou, int op)
// {
//     if (ou)
//     {
//         struct stak *temp = pop(s);

//         if (temp != NULL)
//         {
//             if (temp->op)
//             {
//                 struct node *new = (struct node *)malloc(sizeof(struct node));

//                 new->P_id = temp->ud_node->P_id;
//                 new->price = temp->ud_node->price;
//                 strcpy(new->name, temp->ud_node->name);

//                 new->next = *start;
//                 *start = new;
//             }
//             else
//             {
//                 struct node *temp = *start;
//                 if (start == NULL)
//                 {
//                     printf("\n is empty.");
//                 }
//                 else
//                 {
//                     printf("\n%d is Deleted.", (*start).datum);
//                     start = (*start).next;
//                     free(temp);
//                 }
//                 return start;
//             }
//         }
//         else
//         {
//             printf("\nNothing to undo");
//         }
//     }
//     else
//     {
//     }
// }

// int main()
// {
//     struct node *head = NULL, *end = NULL;
//     struct stak *s = NULL;
//     int choice;
//     for (int i = 0; i < 3; i++)
//     {
//         insert_item(&head);
//     }
//     do
//     {
//         printf("\n----------------------------------------------------------------------");
//         printf("\nWhat you want :\n1.Insert an item\n2.Delete an item.\n3.Display the items\n4.Undo\n5.Exit\n\t\tYour option : ");
//         scanf("%d", &choice);
//         if (choice < 0 || choice > 6)
//         {
//             printf("\n\t\tInvalid input !!!!!!");
//         }
//         else
//         {
//             if (choice == 1)
//             {
//                 insert_item(&head);
//             }
//             else if (choice == 2)
//             {
//                 delete_node(&head);
//             }
//             else if (choice == 3)
//             {
//                 display(head);
//             }
//             else if (choice == 4)
//             {
//                 // undo(head);
//             }
//         }
//     } while (choice != 5);
//       return 0;
//      
// }
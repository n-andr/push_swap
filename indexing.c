#include "push_swap.h"
// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

void	*indexing(t_stack *stack)
{
	int	*array;
	t_stack *tmp;
	int	i;

	tmp = stack;
	i = 0;
	array = NULL;
	array = ft_calloc(sizeof(int), ft_lstsize(stack));
	if (array == NULL)
		return (NULL);
	while (tmp)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	quickSort(array, 0, ft_lstsize(stack) - 1);
	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (tmp->value != array[i])
			i++;
		tmp->index = i;
		tmp = tmp->next;
	}
	free (array);
	return (0);
}
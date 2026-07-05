#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct avlNode_s {
	int					value;
	int					height;
	int					size;
	struct avlNode_s *	left;
	struct avlNode_s *	right;
} avlNode_t;


int Max ( int a, int b ) {
	if ( a > b ) {
		return a;
	} else {
		return b;
	}
}

int Height ( avlNode_t * node ) {
	if ( node == NULL ) {
		return 0;
	}

	return node->height;
}

int Size ( avlNode_t * node ) {
	if ( node == NULL ) {
		return 0;
	}

	return node->size;
}

void UpdateNode ( avlNode_t * node ) {
	if ( node != NULL ) {
		node->height = Max( Height( node->left ), Height( node->right ) ) + 1;
		node->size = Size( node->left ) + Size( node->right ) + 1;
	}
}

avlNode_t * RotateRight ( avlNode_t * y ) {
	avlNode_t * x = y->left;
	avlNode_t * t2 = x->right;

	x->right = y;
	y->left = t2;

	UpdateNode( y );
	UpdateNode( x );

	return x;
}

avlNode_t * RotateLeft ( avlNode_t * x ) {
	avlNode_t * y = x->right;
	avlNode_t * t2 = y->left;

	y->left = x;
	x->right = t2;

	UpdateNode( x );
	UpdateNode( y );

	return y;
}

int GetBalance ( avlNode_t * node ) {
	if ( node == NULL ) {
		return 0;
	}

	return Height( node->left ) - Height( node->right );
}

avlNode_t * Insert_r ( avlNode_t * node, int value, long * inversions ) {
	int balance;

	if ( node == NULL ) {
		avlNode_t * newNode = ( avlNode_t * ) malloc( sizeof( avlNode_t ) );
		newNode->value = value;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->height = 1;
		newNode->size = 1;
		return newNode;
	}

	if ( value < node->value ) {
		*inversions = *inversions + Size( node->right ) + 1;
		node->left = Insert_r( node->left, value, inversions );
	} else if ( value > node->value ) {
		node->right = Insert_r( node->right, value, inversions );
	} else {
		return node;
	}

	UpdateNode( node );

	balance = GetBalance( node );

	if ( balance > 1 && value < node->left->value ) {
		return RotateRight( node );
	}

	if ( balance < -1 && value > node->right->value ) {
		return RotateLeft( node );
	}

	if ( balance > 1 && value > node->left->value ) {
		node->left = RotateLeft( node->left );
		return RotateRight( node );
	}

	if ( balance < -1 && value < node->right->value ) {
		node->right = RotateRight( node->right );
		return RotateLeft( node );
	}

	return node;
}


void FreeTree_r ( avlNode_t * node ) {
	if ( node != NULL ) {
		FreeTree_r( node->left );
		FreeTree_r( node->right );
		free( node );
	}
}

bool isIdealPermutation ( int * nums, int numsSize ) {
	long			localInversions = 0;
	long			globalInversions = 0;
	int				i;
	avlNode_t *		root = NULL;

	for ( i = 0; i < ( numsSize - 1 ); i++ ) {
		if ( nums[ i ] > nums[ i + 1 ] ) {
			localInversions++;
		}
	}

	for ( i = 0; i < numsSize; i++ ) {
		root = Insert_r( root, nums[ i ], &globalInversions );

		if ( globalInversions > localInversions ) {
			FreeTree_r( root );
			return false;
		}
	}

	FreeTree_r( root );

	if ( localInversions == globalInversions ) {
		return true;
	} else {
		return false;
	}
}

int main ( void ) {
	int nums1[] = { 1, 0, 2 };
	int nums2[] = { 1, 2, 0 };

	printf( "Exemplo 1 (esperado: verdadeira): %s\n", isIdealPermutation( nums1, 3 ) ? "verdadeira" : "falsa" );
	printf( "Exemplo 2 (esperado: falsa): %s\n", isIdealPermutation( nums2, 3 ) ? "verdadeira" : "falsa" );

	return 0;
}
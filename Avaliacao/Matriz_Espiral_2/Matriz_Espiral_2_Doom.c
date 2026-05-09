#include <stdio.h>
#include <stdlib.h>

int main( void ) {
    int n;

    printf( "Digite o tamanho da matriz: " );
    fflush( stdout );
    scanf( "%d", &n );

    int **mat = malloc( n * sizeof( int * ) );
    for ( int i = 0; i < n; i++ ) {
        mat[i] = malloc( n * sizeof( int ) );
    }

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int num = 1;

    while ( top <= bottom && left <= right ) {
        
        for ( int i = left; i <= right; i++ ) {
            mat[top][i] = num++;
        }
        top++;

        for ( int i = top; i <= bottom; i++ ) {
            mat[i][right] = num++;
        }
        right--;

        for ( int i = right; i >= left && top <= bottom; i-- ) {
            mat[bottom][i] = num++;
        }
        bottom--;

        for ( int i = bottom; i >= top && left <= right; i-- ) {
            mat[i][left] = num++;
        }
        left++;
    }

    printf( "\n" );

    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            printf( "%3d ", mat[i][j] );
        }
        printf( "\n" );
    }

    for ( int i = 0; i < n; i++ ) {
        free( mat[i] );
    }
    free( mat );

    return 0;
}
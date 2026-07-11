#include <stdio.h>
#include <stdlib.h>

int Compare ( const void * a, const void * b ) {
	const int x = *( const int * ) a;
	const int y = *( const int * ) b;
	if ( x < y ) {
		return -1;
	}
	if ( x > y ) {
		return 1;
	}
	return 0;
}

int FourSumCount ( const int * nums1, const int nums1Size, const int * nums2, const int nums2Size, const int * nums3, const int nums3Size, const int * nums4, const int nums4Size ) {
	const int n = nums1Size;
	const int size = ( n * n );
	int * sums = ( int * ) malloc ( size * sizeof ( int ) );
	int idx = 0;
	int i;
	int j;

	for ( i = 0; ( i < n ); i++ ) {
		for ( j = 0; ( j < n ); j++ ) {
			sums[ idx ] = ( nums1[ i ] + nums2[ j ] );
			idx++;
		}
	}

	qsort ( sums, size, sizeof ( int ), Compare );

	int count = 0;

	for ( i = 0; ( i < n ); i++ ) {
		for ( j = 0; ( j < n ); j++ ) {
			const int target = -( nums3[ i ] + nums4[ j ] );
			int left = 0;
			int right = ( size - 1 );
			int firstPos = -1;

			while ( left <= right ) {
				const int mid = ( left + ( ( right - left ) / 2 ) );
				if ( sums[ mid ] == target ) {
					firstPos = mid;
					right = ( mid - 1 );
				} else if ( sums[ mid ] < target ) {
					left = ( mid + 1 );
				} else {
					right = ( mid - 1 );
				}
			}

			if ( firstPos != -1 ) {
				int k;
				for ( k = firstPos; ( ( k < size ) && ( sums[ k ] == target ) ); k++ ) {
					count++;
				}
			}
		}
	}

	free ( sums );
	return count;
}

int fourSumCount ( int * nums1, int nums1Size, int * nums2, int nums2Size, int * nums3, int nums3Size, int * nums4, int nums4Size ) {
	return FourSumCount ( nums1, nums1Size, nums2, nums2Size, nums3, nums3Size, nums4, nums4Size );
}

int main ( void ) {
	int nums1[] = { 1, 2 };
	int nums2[] = { -2, -1 };
	int nums3[] = { -1, 2 };
	int nums4[] = { 0, 2 };

	const int resultado = fourSumCount ( nums1, 2, nums2, 2, nums3, 2, nums4, 2 );

	printf ( "%d\n", resultado );

	return 0;
}
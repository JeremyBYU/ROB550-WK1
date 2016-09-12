## Results
All numbers are in microseconds (10^-6)

| Method      | 10 X 10 | 100 X 100 | 1000 X 1000  |
| ------------|:-------:| :--------:| :---------:  |
| Numpy       |  73     |  3,038     |   42,050    |
| Pure Python |  577    | 194,541    | 195,347,355 |
| Pure C      |  8      |  3,481     | 18,234,945  |

## Remarks
The pure python multiplication is quite atrocious.
Numpy seems to be very fast.
The pure c implementation looked quite promising for 10X10, and 100 X 100, but falls off quite a bit in the 1000*100
My feeling is that the array access is not very effecient, maybe should have used a stacked array!
void array_addition(int *a, int *b, int *c, int size) {
    #pragma HLS UNROLL
    for (int i = 0; i < size; i++) {
        c[i] = a[i] + b[i];
    }
}

void array_addition(int *a, int *b, int *c, int size) {
    for (int i = 0; i < size; i++) {
        #pragma HLS PIPELINE
        c[i] = a[i] + b[i];
    }
}

void dataflow_example(hls::stream<int> &in1, hls::stream<int> &in2, hls::stream<int> &out) {
    #pragma HLS DATAFLOW
    int tmp1, tmp2;
    read_stream(in1, tmp1);
    read_stream(in2, tmp2);
    out.write(tmp1 + tmp2);
}


void optimized_interface(hls::stream<int> &input, hls::stream<int> &output) {
    #pragma HLS INTERFACE axis port=input
    #pragma HLS INTERFACE axis port=output
    int data;
    while (!input.empty()) {
        data = input.read();
        output.write(data * 2);  // Example processing
    }
}

/*
Summary
Array Addition Functions: Demonstrate different optimization techniques (unrolling and pipelining) for array operations.
Dataflow Example: Illustrates how to utilize the dataflow pragma for concurrent execution.
Optimized Stream Interface: Shows how to handle streaming data efficiently with HLS.
*/

#inlcude <ap_int.h>

void vector_add(ap_int<32> a[100], ap_int<32> b[100], ap_int<32> c[100]) {
	#pragma HLS INTERFACE m_axi port=a depth=100
	#pragma HLS INTERFACE m_axi port=b depth=100
	#pragma HLS INTERFACE m_axi port=c depth=100
	#pragma HLS INTERFACE s_axilite port=return

	for (int i = 0; i < 100; i++) {
		#pragma HLS PIPELINE
		c[i] = a[i] + b[i]
	}
}

/*
Certainly! Let’s dive deeper into the concepts of `m_axi` and `s_axilite` in the context of FPGA design.

+m_axi

1. AXI Memory-Mapped Interfaces:
   - The `m_axi` directive indicates that the function will utilize AXI (Advanced eXtensible Interface) memory-mapped interfaces for managing input and output arrays.
   - AXI is a part of the ARM AMBA (Advanced Microcontroller Bus Architecture) specification, which is widely used in FPGA and SoC (System on Chip) designs due to its high performance and flexibility.

2. Memory Mapping:
   - Memory-mapped interfaces allow the CPU or other processing elements to access peripheral devices and memory using standard read and write operations.
   - This means that the input and output arrays can be directly accessed as if they were regular memory locations, simplifying data transfer between the processing core and memory.

3. Depth=100:
   - The `depth=100` parameter specifies the size of the memory interface. In this case, it indicates that the memory can handle up to 100 entries.
   - This depth can affect the throughput and latency of data transfers. A larger depth typically allows for more data to be processed simultaneously, which is beneficial for performance in high-throughput applications.

+s_axilite

1. AXI Lite Interface:
   - The `s_axilite` directive denotes that the function will have a simple AXI Lite interface. This interface is typically used for control and status registers.
   - Unlike the full AXI interface, which supports burst transactions and complex data transfers, AXI Lite is designed for simpler, single-word transactions. It is primarily used for control signals, configuration, and status monitoring.

2. Control Signals:
   - Control signals are essential for managing the operation of the function. They can include commands to start or stop processing, configure parameters, or read back status information.
   - The AXI Lite interface allows for quick and efficient communication of these control signals without the overhead of more complex data transfers.

3. Return from Function:
   - The ability to return values or status from the function via the AXI Lite interface is crucial for monitoring and debugging. It enables the host processor to check the results of computations or the state of the FPGA logic.

+FPGA Design Considerations

- Memory Interfaces: Efficient memory access is critical in FPGA designs, especially when dealing with high-speed data processing. Using `m_axi` allows designers to leverage the full capabilities of the AXI protocol for high bandwidth and low latency.
  
- Pipelining: FPGAs excel at parallel processing and pipelining. By using AXI interfaces, designers can create architectures that allow for overlapping computation and data transfer, maximizing resource utilization and performance.

- Performance: The combination of `m_axi` for data handling and `s_axilite` for control signals creates a balanced design that can efficiently manage both data flow and control logic, making it suitable for a wide range of applications, from signal processing to data analytics.

+Conclusion

In summary, the `m_axi` and `s_axilite` directives are integral to designing efficient FPGA systems that require robust memory and control interfaces. They enable high-performance data handling and easy management of control signals, which are crucial for effective FPGA operation in various applications. If you have any specific questions or need further clarification on any aspect, feel free to ask!
*/

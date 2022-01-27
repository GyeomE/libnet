#include <stdio.h>
#include <stdlib.h>
#include <libnet.h>
#include <stdint.h>

int main() {
	libnet_t* l; /* libnet context */
	char errbuf[LIBNET_ERRBUF_SIZE], ip_addr_str[16];
	uint32_t ip_addr;
	uint16_t id, seq;
	char payload[] = "libnet :D";
	int bytes_written;
	l = libnet_init(LIBNET_RAW4, NULL, errbuf);
	if (l == NULL) {
		fprintf(stderr, "libnet_init() failed: %s\n", errbuf);
		exit(EXIT_FAILURE);
	}
	/* Generating a random id */
	libnet_seed_prand(l);
	id = (uint16_t)libnet_get_prand(LIBNET_PR16);
	/* Getting destination IP address */
	printf("Destination IP address: ");
	scanf("%15s", ip_addr_str);
	ip_addr = libnet_name2addr4(l, ip_addr_str, \
		LIBNET_DONT_RESOLVE);
	if (ip_addr == -1) {
		fprintf(stderr, "Error converting IP address.\n");
		libnet_destroy(l);
		exit(EXIT_FAILURE);
	}
	//Libnet Á¶»ç 16

		/* Building TCP header */
		seq = 1;
	if (libnet_build_tcp(uint16_t sp,
		uint16_t 	dp,
		uint32_t 	seq,
		uint32_t 	ack,
		uint8_t 	control,
		uint16_t 	win,
		uint16_t 	sum,
		uint16_t 	urg,
		uint16_t 	len,
		uint8_t * payload,
		uint32_t 	payload_s,
		libnet_t * l,
		libnet_ptag_t 	ptag) == -1)
	{
		fprintf(stderr, "Error building ICMP header: %s\n", \
			libnet_geterror(l));
		libnet_destroy(l);
		exit(EXIT_FAILURE);
	}


	/* Building IPv4 header */
	if (libnet_build_ipv4(uint16_t len,
		uint8_t tos, uint16_t id, uint16_t frag,
		uint8_t ttl, uint8_t prot, uint16_t sum,
		uint32_t src, uint32_t dst, uint8_t * payload,
		uint32_t payload_s, libnet_t * l, libnet_ptag_t ptag ) == -1)
	{
		fprintf(stderr, "Error building IP header: %s\n", \
			libnet_geterror(l));
		libnet_destroy(l);
		exit(EXIT_FAILURE);
	}
	/* Building Ethernet header */


	if (libnet_build_ethernet(uint8_t * dst,
		uint8_t * src,
		uint16_t type,
		uint8_t * payload,
		uint32_t 	payload_s,
		libnet_t * l,
		libnet_ptag_t 	ptag) == -1)
	{
		fprintf(stderr, "Error building Ethernet header: %s\n", \
			libnet_geterror(l));
		libnet_destroy(l);
		exit(EXIT_FAILURE);
	}

		/* Writing packet */
	bytes_written = libnet_write(l);
	if (bytes_written != -1)
		printf("%d bytes written.\n", bytes_written);
	else
		fprintf(stderr, "Error writing packet: %s\n", \
			libnet_geterror(l));
	libnet_destroy(l);
	return 0;
}

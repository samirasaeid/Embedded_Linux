#!/bin/bash

function analyze_traffic(){
    #set -x

    local pcap_file="$1";
    i=0
    #echo $pcap_file

    #total_packets=$(tcpdump -r "$pcap_file" | wc -l)
    total_packets=$(tcpdump -r "$pcap_file" | wc -l)
    http_filter_total_packets=$(tcpdump -r "$pcap_file" tcp port 80| wc -l)
    https_filter_total_packets=$(tcpdump -r "$pcap_file" tcp port 443| wc -l)
    top_source_ip_address=$(tcpdump -n -r "$pcap_file" | awk '{print $3}' | sort | uniq -c | sort -nr | awk '{print "   - "$2" : "$1 " packets"}'| head -n 5)
    top_dest_ip_address=$(tcpdump -n -r "$pcap_file" | awk '{print $4}' | sort | uniq -c | sort -nr | awk   '{print "   - " $2" : "$1 " packets"}'| head -n 5)

    echo echo "----- Network Traffic Analysis Report -----"

    # Provide summary information based on your analysis
    # Hints: Total packets, protocols, top source, and destination IP addresses.

    echo "1. Total Packets: [$total_packets]"
    echo "2. Protocols:"
    echo "   - HTTP: [$http_filter_total_packets] packets"
    echo "   - HTTPS/TLS: [$https_filter_total_packets] packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    # Provide the top source IP addresses
    echo "    $top_source_ip_address
    "
    #echo "    - $top_source_ip_address      "
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    # Provide the top destination IP addresses
    echo "    $top_dest_ip_address
    "
    echo ""
    echo "----- End of Report -----"    


}

analyze_traffic "$1"
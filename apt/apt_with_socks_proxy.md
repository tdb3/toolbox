# Overview
Useful when machine needs apt package updates (or new packages), but has no direct internet connectivity

# Establish a socks proxy with SSH

    ssh -D9001 user@host

# Create Configuration

Create /etc/apt/apt.conf.d/proxy.conf, with the following proxy config:

    Acquire::http::proxy "socks5h://127.0.0.1:9001/";
    Acquire::https::proxy "socks5h://127.0.0.1:9001/";
    
# Test
    apt update

#pragma once


// System
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <cerrno>
#include <cstring>

// Standard Template Library
// System
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <cerrno>
#include <cstring>

// Standard Template Library
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <sstream>
#include <stdexcept>

#include <cctype>

// Project Headers
#include "error.hpp"
#include "Client.hpp"
#include "Channel.hpp"
#include "Socket.hpp"
#include "Config.hpp"


#define REDIRC "\033[1;31m"
#define YELLOWIRC "\033[33m"
#define GREENIRC "\033[1;32m"
#define RESETIRC "\033[0m"

class Server {
public:

	Server();
	Server(Config&& configuration);    // Parameterized constructor
	~Server();

	int getPort() const noexcept {return cnfg_.getPort();}
	int getServerFd() const { return serverFd_.getFd(); }
	int getClientFdByNick(const std::string& nick) const;
	std::string getNickByFd(int fd) const;
	void processCommand(int fd, const std::string& message);// Process incoming commands
	void run(); // Start the server

private:
	void ft_send(int fd, const std::string& message);
	void setupServer();                                     // Set up the server
	void mainLoop();                                        // Main loop for handling connections
	void acceptNewConnection();                            // Accept new connections
	void	addClient(Socket& sock);
	void	rmClient(unsigned int rmPollfdIndex, int rmFd);
	void checkRegistration(int fd);                         // Check if client is registered
	void sendWelcome(int fd);                               // Send welcome message to client
	
	
	void cmdNick(int fd, const std::string& message);       // Handle NICK command
	void cmdUser(int fd, const std::string& message);       // Handle USER command
	void cmdJoin(int fd, const std::string& message);       // Handle JOIN command
	void cmdPrivMsg(int fd, const std::string& message);    // Handle PRIVMSG command
	void cmdPing(int fd, const std::string& message);       // Handle PING command
	void cmdTopic(int fd, const std::string& message);     // Handle TOPIC command
	void cmdMode(int fd, const std::string& message);
	void cmdKick(int sender_fd, const std::vector<std::string>& params);      // Handle KICK command
	
	void kickUser(int sender_fd, const std::string& channelName, const std::string& reason, const std::string& targetNick); // Kick user from channel

	Config					cnfg_;
	Socket					serverFd_; // socket wrapper for serverFd_

	std::vector<struct pollfd> pollFds_;                    // Vector of poll file descriptors for clients
	std::map<int, Client> clients_;                         // Map of client file descriptors to Client objects
	int defaultUserCount_ = 0;                              // Default user count for the server
	std::map<std::string, Channel> channels_;               // Map of channel names to Channel objects
};

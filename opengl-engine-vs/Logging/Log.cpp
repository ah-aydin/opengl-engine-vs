#include "Log.h"

#include <fstream>
#include <ctime>
#include <cstdio>
#include <cstdarg>

#ifndef NDEBUG
void gl_log_reset()
{
	// Create a new log file
	std::ofstream out(GL_LOG_FILE);

	// Put the current time in the file
	time_t now = time(NULL);
	char date[26];
	ctime_s(date, sizeof(date), &now);
	out << "OpenGl log file\n";
	out << "Date: " << date << "\n";
}

void gl_log(const char* message, ...)
{
	// Open the log file in append mode
	std::ofstream out(GL_LOG_FILE, std::ios::app);
	if (out.is_open() == false)
	{
		return;
	}

	// Print the log to file
	va_list args;

	va_start(args, message);
	char buffer[4096];
	vsprintf_s(buffer, message, args);
	out << buffer << "\n";
	va_end(args);
}

void gl_log_error(const char* message, ...)
{
	// Open the log file in append mode
	std::ofstream out(GL_LOG_FILE, std::ios::app);
	if (out.is_open() == false)
	{
		return;
	}

	// Print the log to file and stderr
	va_list args;

	va_start(args, message);
	char buffer[4096];
	vsprintf_s(buffer, message, args);
	out << buffer << "\n";
	fprintf(stderr, "%s", buffer);
	fprintf(stderr, "\n");
	va_end(args);
}
#else
void gl_log_reset() { }
void gl_log(const char* message, ...) { }
void gl_log_error(const char* message, ...) { }
#endif
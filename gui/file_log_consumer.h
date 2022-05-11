#pragma once

#include <fstream>
#include "../structures/_logger/logger.h"
namespace gui
{
    class FileLogConsumer
        : public structures::ILogConsumer
    {
    public:
        FileLogConsumer(const std::string& filePath);
        void logMessage(structures::LogType type, const std::string& message) override;
        void logDuration(size_t size, structures::Microseconds duration, const std::string& message) override;
    private:
        std::ofstream fileStream_;
    };
}
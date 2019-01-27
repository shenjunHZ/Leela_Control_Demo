#pragma once

#include <string>
#include <memory>
#include <map>
#include "games/IManagementJob.hpp"
#include "configurations/DefineView.hpp"

namespace games
{
    class Job;
    using gameJobPrt = std::unique_ptr<IJob>;
    using namespace configurations;

    class ManagementJob : public IManagementJob
    {
    public:
        ManagementJob(const std::string& binary, const bool& enableLeelaLog);
        ~ManagementJob();

        void createJobLeela(const leelaStarLevel& level) override;
        const IJob& getJob(const leelaStarLevel& level) override;

    private:
        std::string m_binaryPath;
        bool m_enableGTPEngine;
        bool m_enableLeelaLog;
        std::map<leelaStarLevel, gameJobPrt> m_gameJobs;
    };
}
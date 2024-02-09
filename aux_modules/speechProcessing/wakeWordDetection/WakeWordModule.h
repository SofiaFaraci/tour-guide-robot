#ifndef WAKEWORD_H
#define WAKEWORD_H
#include <string>
#include <cstdio>
#include <iostream>
#include <mutex>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <memory>

#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/os/Time.h>
#include <yarp/sig/Vector.h>
#include <yarp/dev/ILocalization2D.h>
#include <yarp/dev/INavigation2D.h>
#include <yarp/dev/IMap2D.h>
#include <yarp/dev/MapGrid2D.h>
#include <yarp/os/Log.h>
#include <yarp/os/LogStream.h>

#include <yarp/sig/Sound.h>

#include "AudioCallback.h"

#include "WakeServer.h"

#define TIMEOUT_MAX 100

class WakeWordModule : public yarp::os::RFModule
{
    std::string m_rpcClientPortName = "/wake/rpc:o";

public:
    // PARAMETERS

    // devices default parameters
    std::string m_portNameIn = "/wake/audio:i";
    yarp::os::BufferedPort<yarp::sig::Sound> m_audioPort; // input port for audio
    std::shared_ptr<AudioCallback> m_callback = std::make_shared<AudioCallback>(m_rpcClientPortName);

    std::unique_ptr<WakeServer> m_rpcServer;
    yarp::os::RpcServer m_rpcPort;

    double m_period = 0.032;

    bool configure(yarp::os::ResourceFinder &rf) override;
    bool close() override;
    double getPeriod() override;
    bool updateModule() override;

    std::mutex m_mutex;

    //std::unique_ptr<AudioCallback> m_audioCallback;
};

#endif
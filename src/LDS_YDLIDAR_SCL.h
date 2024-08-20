// Copyright 2023-2024 REMAKE.AI, KAIA.AI, MAKERSPET.COM
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Based on https://github.com/YDLIDAR/lidarCar/

#pragma once
#include "LDS_YDLIDAR_X4.h"
#include "PID_v1_0_0.h"

class LDS_YDLIDAR_SCL : public LDS_YDLIDAR_X4 {
  public:
    void init() override;
    virtual result_t start() override;
    virtual result_t stop() override;
    virtual const char* getModelName() override;
    virtual void loop() override;

    virtual float getCurrentScanFreqHz() override;
    virtual uint32_t getSerialBaudRate() override;
    virtual float getTargetScanFreqHz() override;
    virtual int getSamplingRateHz() override;

    virtual result_t setScanTargetFreqHz(float freq) override;
    virtual result_t setScanPIDCoeffs(float Kp, float Ki, float Kd) override;
    virtual result_t setScanPIDSamplePeriodMs(uint32_t sample_period_ms) override;

  protected:
    static constexpr float DEFAULT_SCAN_FREQ_HZ = 5.0f;
    static constexpr float PWM_START = 0.25f;
    virtual void enableMotor(bool enable) override;
    String receiveInfo(uint32_t timeout_ms);

    float scan_freq_setpoint_hz; // desired scan frequency
    float pwm_val;
    float pwm_last;
    PID_v1 scanFreqPID;
};

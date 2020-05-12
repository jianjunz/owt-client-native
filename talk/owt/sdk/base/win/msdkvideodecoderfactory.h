// Copyright (C) <2018> Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0

#ifndef OWT_BASE_WIN_MSDKVIDEODECODERFACTORY_H_
#define OWT_BASE_WIN_MSDKVIDEODECODERFACTORY_H_

#include <d3d11.h>
#include <vector>

#include "webrtc/api/video_codecs/sdp_video_format.h"
#include "webrtc/api/video_codecs/video_decoder.h"
#include "webrtc/api/video_codecs/video_decoder_factory.h"

namespace owt {
namespace base {
// Declaration of MSDK based decoder factory.
class MSDKVideoDecoderFactory : public webrtc::VideoDecoderFactory {
 public:
  MSDKVideoDecoderFactory(ID3D11Device* d3d11_device_external);
  virtual ~MSDKVideoDecoderFactory();

  // VideoDecoderFactory implementation
  std::vector<webrtc::SdpVideoFormat> GetSupportedFormats() const override;

  std::unique_ptr<webrtc::VideoDecoder> CreateVideoDecoder(
      const webrtc::SdpVideoFormat& format) override;
 private:
  std::vector<webrtc::VideoCodecType> supported_codec_types_;
  ID3D11Device* external_device_ = nullptr;
};
}  // namespace base
}  // namespace owt
#endif  // OWT_BASE_WIN_MSDKVIDEODECODERFACTORY_H_

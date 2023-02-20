Pod::Spec.new do |spec|
  spec.name = "WaboCoreIOSSDK"
  spec.version="0.0.5"
  spec.summary = "Wabo SDK core sdk"
  spec.description= <<-DESC
  Wabo SDK for core
  DESC
  spec.homepage= 'https://github.com/bepic-games/WaboCoreIOSSDK'
  spec.license= { :type => 'MIT', :file => 'LICENSE' }
  spec.author = { "yilang" => "yilang@bepic.cc" }
  spec.ios.deployment_target = "11.0"
  spec.source = { :git => "https://github.com/bepic-games/WaboCoreIOSSDK.git", :tag => "#{spec.version}" }
  spec.source_files= 'WaboCoreIOSSDK/*.{framework}/Headers/*.h'
  spec.vendored_frameworks = 'WaboCoreIOSSDK/*.{framework}'
  spec.public_header_files = 'WaboCoreIOSSDK/*.{framework}/Headers/*.h'
  spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'arm64' }
  spec.swift_version = '5.0'
  spec.dependency 'AliyunLogProducer', '2.2.25'
  spec.dependency 'SAMKeychain', '1.5.3'
  spec.dependency 'Adjust', '4.32.1'
end

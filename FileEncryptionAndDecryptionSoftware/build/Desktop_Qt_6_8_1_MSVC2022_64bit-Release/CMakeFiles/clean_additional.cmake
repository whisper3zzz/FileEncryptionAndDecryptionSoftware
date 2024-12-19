# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\FileEncryptionAndDecryptionSoftware_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FileEncryptionAndDecryptionSoftware_autogen.dir\\ParseCache.txt"
  "FileEncryptionAndDecryptionSoftware_autogen"
  )
endif()

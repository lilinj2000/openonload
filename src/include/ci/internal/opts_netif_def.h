/*
** Copyright 2005-2016  Solarflare Communications Inc.
**                      7505 Irvine Center Drive, Irvine, CA 92618, USA
** Copyright 2002-2005  Level 5 Networks Inc.
**
** This program is free software; you can redistribute it and/or modify it
** under the terms of version 2 of the GNU General Public License as
** published by the Free Software Foundation.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/

/**************************************************************************\
*//*! \file
** <L5_PRIVATE L5_HEADER >
** \author  cgg
**  \brief  Definition of configuration options held in a netif
**   \date  2005/11/30
**    \cop  (c) Level 5 Networks Limited.
** </L5_PRIVATE>
*//*
\**************************************************************************/


/* This file is included in a number of different environments to obtain a
   representation of configuration options.  It must contain ONLY C
   pre-procesor symbols.

   It must include one instance of the macro
   
       CI_CFG_OPTFILE_VERSION(version) - version of this option set
       
   This version number should be incremented if the meaning of current or
   former option names changes.

   It then has an arbitrary number of
   
       CI_CFG_OPT(env, name, type, doc, type_modifier, group, default,
                  min, max, presentation)

   option definitions:

       env           - a string giving the enviornment variable used to control
                       this option.
       name          - the C name of this option
       type          - an integer C type used to hold the option in
       doc           - a user-facing documentation documentation string
                       describing the option
       type_modifier - an integer giving size of the bitfield it is in or
                       an alignment requirement A<n> for aligning on an
		       <n>-byte boundary
       group         - a name for the option group this option belongs to,
                       by default (if nothing is placed in this field)
		       the name (above) is used
                       option groups define sets of options all of which must
		       be defined if any are
       default       - the value to which the option should be initialized
                       the values MIN, MAX, SMIN, SMAX can be used to refer to
		       the unsigned and signed minimum and maximum values that
		       fit in the field
       min           - the integer minimum value the option can hold
                       the values MIN, MAX, SMIN, SMAX can be used to refer to
		       the unsigned and signed minimum and maximum values that
		       fit in the field
       max           - the integer maximum value the option can hold
                       the values MIN, MAX, SMIN, SMAX can be used to refer to
		       the unsigned and signed minimum and maximum values that
		       fit in the field
		       Note: currently MAX is unlikely to be treated properly
		       in an unsigned 64-bit field - you should use SMAX
       presentation  - a name for the presentation type used to determine the
                       way this value should be presented to a user currently
		       one of:
		           count	- number of elements in something
		           countln2	- " as a power of two
			   bincount     - number of binary things, e.g. bytes
			   level        - one of a set of relative levels
			   time:sec     - time in seconds
			   time:msec    - time in milliseconds
			   time:usec    - time in microseconds
			   time:tick    - time in host-specific units
			   invcount     - a rate/probability of 1 in this many
			   bitmask      - bit mask
			   bitset:<S1>;..<Sn>
			                - bit set composed of bit 0==S1 |
					  bit 1=S2 ... | <bit n-1=Sn
			   ipaddress    - IP address
			   ipmask       - IP address mask
			   oneof:<S1>;..;<Sn>
			                - enumeration where minimum==S1
			   yesno        - same as oneof:no;yes
			   filename     - name of a file
                      

   Finally it can contain an arbitrary number of
   
       CI_CFG_OPTGROUP(group, category, expertise)

   option group definitions:

       group         - name of the option group (as used in CI_CFG_OPT)
       category      - name for the category of option these options belong to
                       options from the same category may be presented to
		       a user for modification grouped together
		       by default (if nothing is placed in this field)
		       the name of the group is used
       expertise     - an integer giving the expertise level associated with
                       these options
		       options with expertise level greater than that of the
		       user may not be presented to him for modification
		       by default the value 100 should be used

   Option groups generated implicitly by CI_CFG_OPT macros, which are
   unmodified by a CI_CFG_OPTGROUP macro should be considered to have a
   category with the same name as the option group and an expertise level
   equal to 100
*/


/* Please think carefully about packing when adding fields to this data
** structure.  Small fields should be next to each other to avoid wasting
** space.
**
** Please do not remove the sequence  0, MIN, MAX  on every option on the
** grounds that it is common text - they are there as in invitation to
** consider more correct values.
*/
#ifdef CI_CFG_OPTFILE_VERSION
CI_CFG_OPTFILE_VERSION(100)
#endif


/************************* FLAGS SECTION *************************/

CI_CFG_OPT("EF_URG_RFC", urg_rfc, ci_uint32,
"Choose between compliance with RFC1122 (1) or BSD behaviour (0) regarding "
"the location of the urgent point in TCP packet headers.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TX_PUSH", tx_push, ci_uint32,
"Enable low-latency transmit.",
           1, , 1, 0, 1, yesno)

/* Takes its value from EF_ACCEPT_INHERIT_NONBLOCK in opts_citp_def.  Do
 * not document this one here.
 */
CI_CFG_OPT("", accept_inherit_nonblock, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_POLL_ON_DEMAND", poll_on_demand, ci_uint32,
"Poll for network events in the context of the application calls into the "
"network stack.  This option is enabled by default."
"\n"
"This option can improve performance in multi-threaded applications where "
"the Onload stack is interrupt-driven (EF_INT_DRIVEN=1), because it can "
"reduce lock contention.  Setting EF_POLL_ON_DEMAND=0 ensures that network "
"events are (mostly) processed in response to interrupts.",
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_INT_DRIVEN", int_driven, ci_uint32,
"Put the stack into an 'interrupt driven' mode of operation.  When this "
"option is not enabled Onload uses heuristics to decide when to enable "
"interrupts, and this can cause latency jitter in some applications.  So "
"enabling this option can help avoid latency outliers."
"\n"
"This option is enabled by default except when spinning is enabled."
"\n"
"This option can be used in conjunction with spinning to prevent outliers "
"caused when the spin timeout is exceeded and the application blocks, or when "
"the application is descheduled.  In this case we recommend that interrupt "
"moderation be set to a reasonably high value (eg. 100us) to prevent too high "
"a rate of interrupts.",
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_INT_REPRIME", int_reprime, ci_uint32,
"Enable interrupts more aggressively than the default.",
           1, , 0, 0, 1, yesno)

#if CI_CFG_UDP
#define MULTICAST_LIMITATIONS_NOTE                                      \
    "\nSee the OpenOnload manual for further details on multicast operation."

CI_CFG_OPT("EF_MCAST_RECV", mcast_recv, ci_uint32,
"Controls whether or not to accelerate multicast receives.  When set to zero, "
"multicast receives are not accelerated, but the socket continues to be "
"managed by Onload."
"\n"
"See also EF_MCAST_JOIN_HANDOVER."
MULTICAST_LIMITATIONS_NOTE,
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_FORCE_SEND_MULTICAST", force_send_multicast, ci_uint32,
"This option causes all multicast sends to be accelerated.  When disabled, "
"multicast sends are only accelerated for sockets that have cleared the "
"IP_MULTICAST_LOOP flag."
"\n"
"This option disables loopback of multicast traffic to receivers on the same "
"host, unless\n"
"(a) those receivers are sharing an OpenOnload stack with the sender "
"(see EF_NAME) and EF_MCAST_SEND is set to 1 or 3, or\n"
"(b) prerequisites to support loopback to other OpenOnload stacks are met "
"(see EF_MCAST_SEND)."
MULTICAST_LIMITATIONS_NOTE,
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_MULTICAST_LOOP_OFF", multicast_loop_off, ci_uint32,
"EF_MULTICAST_LOOP_OFF is deprecated in favour of EF_MCAST_SEND\n"
"When set, disables loopback of multicast traffic to receivers in the same "
"OpenOnload stack.\n"
"This option only takes effect when EF_MCAST_SEND is not set and is "
"equivalent to EF_MCAST_SEND=1 or EF_MCAST_SEND=0 "
"for values of 0 and 1 respectively."
MULTICAST_LIMITATIONS_NOTE,
           1, , 1, 0, 1, yesno)

#define CITP_MCAST_SEND_FLAG_LOCAL 1
#define CITP_MCAST_SEND_FLAG_EXT 2

CI_CFG_OPT("EF_MCAST_SEND", mcast_send, ci_uint32,
"Controls loopback of multicast traffic to receivers in the same and other "
"OpenOnload stacks.\n"
"When set to 0 (default) disables loopback within the same stack as well as to "
"other OpenOnload stacks.\n"
"When set to 1 enables loopback to the same stack\n"
"When set to 2 enables loopback to other OpenOnload stacks.\n"
"When set to 3 enables loopback to the same as well as other OpenOnload "
"stacks.\n"
"In respect to loopback to other OpenOnload stacks the options is just a hint "
"and the feature requires: (a) 7000-series or newer device, and "
"(b) selecting firmware variant with loopback support."
MULTICAST_LIMITATIONS_NOTE,
           2, , 0, 0, 3, oneof:none;local;ext;all;)

CI_CFG_OPT("EF_MCAST_RECV_HW_LOOP", mcast_recv_hw_loop, ci_uint32,
"When enabled allows udp sockets to receive multicast traffic that "
"originates from other OpenOnload stacks."
MULTICAST_LIMITATIONS_NOTE,
           1, , 1, 0, 1, yesno)

#endif

CI_CFG_OPT("EF_TCP_LISTEN_HANDOVER", tcp_listen_handover, ci_uint32,
"When an accelerated TCP socket calls listen(), hand it over to the kernel "
"stack.  This option disables acceleration of TCP listening sockets and "
"passively opened TCP connections.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_CONNECT_HANDOVER", tcp_connect_handover, ci_uint32,
"When an accelerated TCP socket calls connect(), hand it over to the kernel "
"stack.  This option disables acceleration of active-open TCP connections.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_UDP_CONNECT_HANDOVER", udp_connect_handover, ci_uint32,
"When a UDP socket is connected to an IP address that cannot be accelerated "
"by OpenOnload, hand the socket over to the kernel stack.\n"

"When this option is disabled the socket remains under the control of "
"OpenOnload.  This may be worthwhile because the socket may subsequently be "
"re-connected to an IP address that can be accelerated.",
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_FORCE_TCP_NODELAY", tcp_force_nodelay, ci_uint32,
"This option allows the user to override the use of TCP_NODELAY. "
"This may be useful in cases where 3rd-party software is (not) "
"setting this value and the user would like to control its "
"behaviour:\n"
"  0 - do not override"
"  1 - always set TCP_NODELAY"
"  2 - never set TCP_NODELAY",
           2, , 0, 0, 2, level)

#if CI_CFG_UDP
# if CI_CFG_UDP_SEND_UNLOCK_OPT
CI_CFG_OPT("EF_UDP_SEND_UNLOCKED", udp_send_unlocked, ci_uint32,
"Enables the 'unlocked' UDP send path.  When enabled this option improves "
"concurrency when multiple threads are performing UDP sends.",
           1, , 1, 0, 1, yesno)
# endif
#endif

CI_CFG_OPT("EF_UNCONFINE_SYN", unconfine_syn, ci_uint32,
"Accept TCP connections that cross into or out-of a private network.",
           1, , 1, 0, 1, yesno)

CI_CFG_OPT("EF_BINDTODEVICE_HANDOVER", bindtodevice_handover, ci_uint32,
"Hand sockets over to the kernel stack that have the SO_BINDTODEVICE socket "
"option enabled.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_MCAST_JOIN_BINDTODEVICE", mcast_join_bindtodevice, ci_uint32,
"When a UDP socket joins a multicast group (using IP_ADD_MEMBERSHIP or "
"similar), this option causes the socket to be bound to the interface that "
"the join was on.  The benefit of this is that it ensures the socket will "
"not accidentally receive packets from other interfaces that happen to match "
"the same group and port.  This can sometimes happen if another socket joins "
"the same multicast group on a different interface, or if the switch is "
"not filtering multicast traffic effectively."
"\n"
"If the socket joins multicast groups on more than one interface, then the "
"binding is automatically removed.",
           1, , 0, 0, 1, yesno)

#if CI_CFG_RATE_PACING
CI_CFG_OPT("EF_TX_QOS_CLASS", tx_qos_class, ci_uint32,
"Set the QOS class for transmitted packets on this Onload stack.  Two QOS "
"classes are supported: 0 and 1.  By default both Onload accelerated traffic "
"and kernel traffic are in class 0.  You can minimise latency by placing "
"latency sensitive traffic into a separate QOS class from bulk traffic.",
           1, , 0, 0, 1, yesno)
#endif

CI_CFG_OPT("EF_TCP_RX_CHECKS", tcp_rx_checks, ci_uint32,
"Internal/debugging use only: perform extra debugging/consistency checks "
"on received packets.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_USE_DSACK", use_dsack, ci_uint32,
"Whether or not to use DSACK (duplicate SACK).",
           1, , CI_CFG_TCP_DSACK, 0, 1, yesno)

#define CITP_TIMESTAMPING_RECORDING_FLAG_CHECK_SYNC 1
CI_CFG_OPT("EF_TIMESTAMPING_REPORTING", timestamping_reporting, ci_uint32,
"Controls timestamp reporting, possible values:\n"
" 0: report translated timestamps only when the NIC clock has been set;\n"
" 1: report translated timestamps only when the system clock and the NIC "
"clock are in sync (e.g. using ptpd)\n"
"If the above conditions are not met Onload will only report raw "
"(not translated) timestamps.\n",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_RX_TIMESTAMPING", rx_timestamping, ci_uint32,
"Control of hardware timestamping of received packets, possible values:\n"
"  0 - do not do timestamping (default);\n"
"  1 - request timestamping but continue if hardware is not capable or it"
" does not succeed;\n"
"  2 - request timestamping and fail if hardware is capable and it does"
" not succeed;\n"
"  3 - request timestamping and fail if hardware is not capable or it"
" does not succeed;\n",
           2, , 0, 0, 3, count)

CI_CFG_OPT("EF_TX_TIMESTAMPING", tx_timestamping, ci_uint32,
"Control of hardware timestamping of transmitted packets, possible values:\n"
"  0 - do not do timestamping (default);\n"
"  1 - request timestamping but continue if hardware is not capable or it"
" does not succeed;\n"
"  2 - request timestamping and fail if hardware is capable and it does"
" not succeed;\n"
"  3 - request timestamping and fail if hardware is not capable or it"
" does not succeed;\n",
           2, , 0, 0, 3, count)

CI_CFG_OPT("EF_CLUSTER_IGNORE", cluster_ignore, ci_uint32,
"When set, this option instructs Onload to ignore attempts to use clusters and "
"effectively ignore attempts to set SO_REUSEPORT.",
           1, , 0, 0, 1, count)

CI_CFG_OPT("EF_VALIDATE_ENV", validate_env, ci_uint32,
"When set this option validates Onload related environment "
"variables (starting with EF_).",
           1, , 1, 0, 1, level)

#if CI_CFG_TAIL_DROP_PROBE
CI_CFG_OPT("EF_TAIL_DROP_PROBE", tail_drop_probe, ci_uint32,
/* FIXME: when shoudl one use this? */
"Whether to probe if the tail of a TCP burst isn't ACKed quickly.",
           , , 1, 0, 1, yesno)
#endif

/* These EF_*_SPIN options are only here so that the application defaults
 * set by environment variables get exposed through stackdump.  (Because
 * stackdump only has visibility of per-stack options).
 */
CI_CFG_OPT("EF_SELECT_SPIN", ul_select_spin, ci_uint32,
           "", 1, ,0, 0, 1, yesno)

CI_CFG_OPT("EF_POLL_SPIN", ul_poll_spin, ci_uint32, 
           "", 1, ,0, 0, 1, yesno)

#if CI_CFG_USERSPACE_EPOLL
CI_CFG_OPT("EF_EPOLL_SPIN", ul_epoll_spin, ci_uint32, 
           "", 1, , 0, 0, 1, yesno)
#endif

#if CI_CFG_UDP
CI_CFG_OPT("EF_UDP_RECV_SPIN", udp_recv_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_UDP_SEND_SPIN", udp_send_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)
#endif

CI_CFG_OPT("EF_TCP_RECV_SPIN", tcp_recv_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_SEND_SPIN", tcp_send_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_ACCEPT_SPIN", tcp_accept_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_CONNECT_SPIN", tcp_connect_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_PKT_WAIT_SPIN", pkt_wait_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

#if CI_CFG_USERSPACE_PIPE
CI_CFG_OPT("EF_PIPE_RECV_SPIN", pipe_recv_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_PIPE_SEND_SPIN", pipe_send_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_PIPE_SIZE", pipe_size, ci_uint32,
           "", , , OO_PIPE_DEFAULT_SIZE, OO_PIPE_MIN_SIZE,
           CI_CFG_MAX_PIPE_SIZE, count)
#endif

CI_CFG_OPT("EF_SOCK_LOCK_BUZZ", sock_lock_buzz, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_STACK_LOCK_BUZZ", stack_lock_buzz, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_SO_BUSY_POLL_SPIN", so_busy_poll_spin, ci_uint32,
           "", 1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_RST_DELAYED_CONN", rst_delayed_conn, ci_uint32,
"This option tells Onload to reset TCP connections rather than allow data to "
"be transmitted late.  Specifically, TCP connections are reset if the "
"retransmit timeout fires.  (This usually happens when data is lost, and "
"normally triggers a retransmit which results in data being delivered "
"hundreds of milliseconds late)."
"\n"
"WARNING: This option is likely to cause connections to be reset spuriously "
"if ACK packets are dropped in the network.",
          1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_SNDBUF_MODE", tcp_sndbuf_mode, ci_uint32,
           "This option controls how the SO_SNDBUF limit is applied to TCP "
           "sockets.  In the default mode the limit applies to the "
           "size of the send queue and retransmit queue combined.  "
           "When this option is set to 0 the limit applies to the "
           "the send queue only."
           "When this option is set to 2, the SNDBUF size is automatically "
           "adjusted for each TCP socket to match the window advertised by "
           "the peer (limited by EF_TCP_SOCKBUF_MAX_FRACTION). If the"
           "application sets SO_SNDBUF explictly then automatic adjustment is"
           "not used for that socket. The limit is applied to the size of the"
           "send queue and retransmit queue combined. You may also want to set"
           "EF_TCP_RCVBUF_MODE to give automatic adjustment of RCVBUF.",
           2, , 1, 0, 2, oneof:no;yes;auto)

CI_CFG_OPT("EF_TCP_SOCKBUF_MAX_FRACTION", tcp_sockbuf_max_fraction, ci_uint32,
           "This option controls the maximum fraction of the TX buffers"
           "that may be allocated to a single socket with EF_TCP_SNDBUF_MODE=2."
           "It also controls the maximum fraction of the RX buffers that may"
           "be allocated to a single socket with EF_TCP_RCVBUF_MODE=1."
           "The maximum allocation for a socket is EF_MAX_TX_PACKETS/(2^N)"
           "for TX and EF_MAX_RX_PACKETS/(2^N) for RX, where N is specified"
           "here.",
           4, , 1, 1, 10, count)

CI_CFG_OPT("EF_TCP_SYNCOOKIES", tcp_syncookies, ci_uint32,
"Use TCP syncookies to protect from SYN flood attack",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_SEND_NONBLOCK_NO_PACKETS_MODE", 
           tcp_nonblock_no_pkts_mode, ci_uint32,
           "This option controls how a non-blocking TCP send() call should "
           "behave if it is unable to allocate sufficient packet buffers.  By "
           "default Onload will mimic Linux kernel stack behaviour and block "
           "for packet buffers to be available.  If set to 1, this option will "
           "cause Onload to return error ENOBUFS.  Note this option can cause "
           "some applications (that assume that a socket that is writeable is "
           "able to send without error) to malfunction.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_RCVBUF_STRICT", tcp_rcvbuf_strict, ci_uint32,
"This option prevents TCP small segment attack.  With this option set, "
"Onload limits the number of packets inside TCP receive queue and "
"TCP reorder buffer.  In some cases, this option causes performance "
"penalty.  You probably want this option if your application is "
"connecting to unrtusted partner or over untrusted network.\n"
"Off by default.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_UDP_SEND_NONBLOCK_NO_PACKETS_MODE", 
           udp_nonblock_no_pkts_mode, ci_uint32,
           "This option controls how a non-blocking UDP send() call should "
           "behave if it is unable to allocate sufficient packet buffers.  By "
           "default Onload will mimic Linux kernel stack behaviour and block "
           "for packet buffers to be available.  If set to 1, this option will "
           "cause Onload to return error ENOBUFS.  Note this option can cause "
           "some applications (that assume that a socket that is writeable is "
           "able to send without error) to malfunction.",
           1, , 0, 0, 1, yesno)

CI_CFG_OPT("EF_TCP_RCVBUF_MODE", tcp_rcvbuf_mode, ci_uint32,
"This option controls how the RCVBUF is set for TCP "
"Mode 0 (default) gives fixed size RCVBUF."
"Mode 1 will enable automatic tuning of RCVBUF using Dynamic Right Sizing."
"       If SO_RCVBUF is explictly set by the application this value will be"
"       used. EF_TCP_SOCKBUF_MAX_FRACTION can be used to control the maximum"
"       size of the buffer for an individual socket."
"The effect of EF_TCP_RCVBUF_STRICT is independent of this setting.",
	   1, , 0, 0, 1, yesno)

/**********************************************************************
 * Narrow fields (few bits).
 */

CI_CFG_OPT("EF_MCAST_JOIN_HANDOVER", mcast_join_handover, ci_uint32,
"When this option is set to 1, and a UDP socket joins a multicast group on an "
"interface that is not accelerated, the UDP socket is handed-over to the "
"kernel stack.  This can be a good idea because it prevents that socket from "
"consuming Onload resources, and may also help avoid spinning when it is not "
"wanted."
"\n"
"When set to 2, UDP sockets that join multicast groups are always handed-over "
"to the kernel stack.",
           2, , 0, 0, 2, oneof:off;kernel;always)

#if CI_CFG_POISON_BUFS
CI_CFG_OPT("EF_POISON_RX_BUF", poison_rx_buf, ci_uint32,
"1=hdrs 2=payload also.",
           2, , 0, 0, 2, oneof:no;headers;headersandpayload)
#endif

/* packet_buffer_mode bits to be ORed: */
#define CITP_PKTBUF_MODE_VF      1
#define CITP_PKTBUF_MODE_PHYS    2
CI_CFG_OPT("EF_PACKET_BUFFER_MODE", packet_buffer_mode, ci_uint32,
"This option affects how DMA buffers are managed.  The default packet buffer "
"mode uses a limited hardware resource, and so restricts the total amount "
"of memory that can be used by Onload for DMA."
"\n"
"Setting EF_PACKET_BUFFER_MODE!=0 enables 'scalable packet buffer mode' which "
"removes that limit.  See details for each mode below."
"\n"
"  1  -  SR-IOV with IOMMU.  Each stack allocates a separate PCI Virtual "
"Function.  IOMMU guarantees that different stacks do not have any access "
"to each other data."
"\n"
"  2  -  Physical address mode.  Inherently unsafe; no address space "
"separation between different stacks or net driver packets."
"\n"
"  3  -  SR-IOV with physical address mode.  Each stack allocates a "
"separate PCI Virtual Function.  IOMMU is not used, so this mode is unsafe "
"in the same way as (2)."
"\n"
"To use odd modes (1 and 3) SR-IOV must be enabled in the BIOS, "
"OS kernel and on the network adapter.  In these modes you also get faster "
"interrupt handler which can improve latency for some workloads."
"\n"
"For mode (1) you also have to enable IOMMU (also known as VT-d) in BIOS"
"and in your kernel."
"\n"
"For unsafe physical address modes (2) and (3), you should tune "
"phys_mode_gid module parameter of the onload module.",
           2, , 0, 0, 3, oneof:buf_table;sriov_iommu;phys;sriov_phys)

#define CITP_TCP_LOOPBACK_OFF           0
#define CITP_TCP_LOOPBACK_SAMESTACK     1
#define CITP_TCP_LOOPBACK_TO_CONNSTACK  2
#define CITP_TCP_LOOPBACK_ALLOW_ALIEN_IN_ACCEPTQ 2
#define CITP_TCP_LOOPBACK_TO_LISTSTACK  3
#define CITP_TCP_LOOPBACK_TO_NEWSTACK   4

CI_CFG_OPT("EF_TCP_SERVER_LOOPBACK", tcp_server_loopback, ci_uint32,
"Enable acceleration of TCP loopback connections on the listening (server) "
"side:\n"
"  0  -  not accelerated (default);\n"
"  1  -  accelerate if the connecting socket is in the same stack (you "
"should also set EF_TCP_CLIENT_LOOPBACK!=0);\n"
"  2  -  accelerate and allow accepted socket to be in another stack "
"(this is necessary for clients with EF_TCP_CLIENT_LOOPBACK=2,4).",
           2, , CITP_TCP_LOOPBACK_OFF, 0,
           CITP_TCP_LOOPBACK_ALLOW_ALIEN_IN_ACCEPTQ,
           oneof:no;samestack;allowalien)

CI_CFG_OPT("EF_TCP_CLIENT_LOOPBACK", tcp_client_loopback, ci_uint32,
"Enable acceleration of TCP loopback connections on the connecting (client) "
"side:\n"
"  0  -  not accelerated (default);\n"
"  1  -  accelerate if the listening socket is in the same stack "
"(you should also set EF_TCP_SERVER_LOOPBACK!=0);\n"
"  2  -  accelerate and move accepted socket to the stack of the connecting "
"socket (server should allow this via EF_TCP_SERVER_LOOPBACK=2);\n"
"  3  -  accelerate and move the connecting socket to the stack of the "
"listening socket (server should allow this via EF_TCP_SERVER_LOOPBACK!=0).\n"
"  4  -  accelerate and move both connecting and accepted  sockets to the "
"new stack (server should allow this via EF_TCP_SERVER_LOOPBACK=2).\n"
"\n"
"NOTES:\nOptions 3 and 4 break some applications using epoll, fork and "
"dup calls.\n"
"Options 2 and 4 makes accept() to misbehave if the client exist "
"too early.\n"
"Option 4 is not recommended on 32-bit systems because it can create "
"a lot of additional Onload stacks eating a lot of low memory.",
           3, , CITP_TCP_LOOPBACK_OFF, 0, CITP_TCP_LOOPBACK_TO_NEWSTACK,
           oneof:no;samestack;toconn;tolist;nonew)

#if CI_CFG_PKTS_AS_HUGE_PAGES
CI_CFG_OPT("EF_USE_HUGE_PAGES", huge_pages, ci_uint32,
"Control of whether huge pages are used for packet buffers:\n"
"  0 - no;\n"
"  1 - use huge pages if available (default);\n"
"  2 - always use huge pages and fail if huge pages are not available.\n"
"Mode 1 prints syslog message if there is not enough huge pages "
"in the system.\n"
"Mode 2 guarantees only initially-allocated packets to be in huge pages.  "
"It is recommended to use this mode together with EF_MIN_FREE_PACKETS, "
"to control the number of such guaranteed huge pages.  All non-initial "
"packets are allocated in huge pages when possible; syslog message is "
"printed if the system is out of huge pages.\n"
"Non-initial packets may be allocated in non-huge pages without "
"any warning in syslog for both mode 1 and 2 even if the system has "
"free huge pages.",
           2, , 1, 0, 2, oneof:no;try;always)
#endif

CI_CFG_OPT("EF_COMPOUND_PAGES_MODE", compound_pages, ci_uint32,
"Debug option, not suitable for normal use.\n"
"For packet buffers, allocate system pages in the following way:\n"
"  0 - try to use compound pages if possible (default);\n"
"  1 - do not use compound pages of high order;\n"
"  2 - do not use compound pages at all.\n",
          2, , 0, 0, 2, oneof:always;small;never)

#if CI_CFG_PIO
CI_CFG_OPT("EF_PIO", pio, ci_uint32,
"Control of whether Programmed I/O is used instead of DMA for small packets:\n"
"  0 - no (use DMA);\n"
"  1 - use PIO for small packets if available (default);\n"
"  2 - use PIO for small packets and fail if PIO is not available.\n"
"Mode 1 will fall back to DMA if PIO is not currently available.\n"
"Mode 2 will fail to create the stack if the hardware supports PIO but "
"PIO is not currently available.  On hardware that does not support PIO "
"there is no difference between mode 1 and mode 2\n"
"In all cases, PIO will only be used for small packets (see EF_PIO_THRESHOLD) "
"and if the VI's transmit queue is currently empty.  If these conditions are "
"not met DMA will be used, even in mode 2.\n"
"Note: PIO is currently only available on x86_64 systems\n"
"Note: Mode 2 will not prevent a stack from operating without PIO in the\n"
"      event that PIO allocation is originally successful but then fails\n"
"      after an adapter is rebooted or hotplugged while that stack exists.",
           2, , 1, 0, 2, oneof:no;try;always)
#endif

CI_CFG_OPT("EF_SYNC_CPLANE_AT_CREATE", sync_cplane, ci_uint32,
"When this option is set to 2 Onload will force a sync of control plane "
"information from the kernel when a stack is created.  This can help to "
"ensure up to date information is used where a stack is created immediately "
"following interface configuration."
"\n"
"If this option is set to 1 then Onload will only force a sync for the first "
"stack created.  This can be used if stack creation time for later stacks "
"is time critical."
"\n"
"Setting this option to 0 will disable forced sync.  Synchronising data from "
"the kernel will continue to happen periodically.",
           2, , 2, 0, 2, oneof:never;first;always)

CI_CFG_OPT("EF_TCP_SYN_OPTS", syn_opts, ci_uint32,
"A bitmask specifying the TCP options to advertise in SYN segments.\n"
"bit 0 (0x1) is set to 1 to enable PAWS and RTTM timestamps (RFC1323),\n"
"bit 1 (0x2) is set to 1 to enable window scaling (RFC1323),\n"
"bit 2 (0x4) is set to 1 to enable SACK (RFC2018),\n"
"bit 3 (0x8) is set to 1 to enable ECN (RFC3128).",
           4, , CI_TCPT_SYN_FLAGS, MIN, MAX, bitmask)

CI_CFG_OPT("EF_TCP_ADV_WIN_SCALE_MAX", tcp_adv_win_scale_max, ci_uint32,
"Maximum value for TCP window scaling that will be advertised.",
           4, , CI_TCP_WSCL_MAX, 0, 14, bincount)

CI_CFG_OPT("EF_TCP_TCONST_MSL", msl_seconds, ci_uint32,
"The Maximum Segment Lifetime (as defined by the TCP RFC).  A smaller value "
"causes connections to spend less time in the TIME_WAIT state.",
           8, , CI_CFG_TCP_TCONST_MSL, MIN, MAX, time:sec)

CI_CFG_OPT("EF_TCP_FIN_TIMEOUT", fin_timeout, ci_uint32,
"Time in seconds to wait for an orphaned connection to be closed properly "
"by the network partner (e.g. FIN in the TCP FIN_WAIT2 state; zero window "
"opening to send our FIN, etc).",
           8, , CI_CFG_TCP_FIN_TIMEOUT, MIN, MAX, time:sec /*?*/)

CI_CFG_OPT("EF_TCP_RX_LOG_FLAGS", tcp_rx_log_flags, ci_uint32,
"Log received packets that have any of these flags set in the TCP header.  "
"Only active when EF_TCP_RX_CHECKS is set.",
           8, ,  0, MIN, MAX, bitmask)

#if CI_CFG_PORT_STRIPING
CI_CFG_OPT("EF_STRIPE_DUPACK_THRESHOLD", stripe_dupack_threshold, ci_uint16,
"For connections using port striping: Sets the number of duplicate ACKs that "
"must be received before initiating fast retransmit.",
           8, , CI_CFG_STRIPE_DEFAULT_DUPACK_THRESHOLD, MIN, MAX, count/*?*/)

CI_CFG_OPT("EF_STRIPE_TCP_OPT", stripe_tcp_opt, ci_uint32,
"The TCP option number to use when negotiating port striping.",
           8, , CI_CFG_STRIPE_DEFAULT_TCP_OPT, MIN, MAX, bitmask)
#endif

CI_CFG_OPT("EF_RETRANSMIT_THRESHOLD", retransmit_threshold, ci_int32,
"Number of retransmit timeouts before a TCP connection is aborted.",
           8,  retransmit_threshold, CI_TCP_RETRANSMIT_THRESHOLD,
           0, SMAX, count)

CI_CFG_OPT("EF_RETRANSMIT_THRESHOLD_ORPHAN", retransmit_threshold_orphan, ci_int32,
"Number of retransmit timeouts before a TCP connection is aborted "
"in case of orphaned connection.",
           8,  retransmit_threshold, CI_TCP_RETRANSMIT_THRESHOLD_ORPHAN,
           0, SMAX, count)

CI_CFG_OPT("EF_RETRANSMIT_THRESHOLD_SYN", retransmit_threshold_syn, ci_int32,
"Number of times a SYN will be retransmitted before a connect() attempt will "
"be aborted.",
           8,  retransmit_threshold, CI_TCP_RETRANSMIT_THRESHOLD_SYN,
           0, SMAX, count)

#define CI_TCP_LISTEN_SYNACK_RETRIES 5   /* send 5 synacks by default */
CI_CFG_OPT("EF_RETRANSMIT_THRESHOLD_SYNACK", retransmit_threshold_synack,
           ci_int32,
"Number of times a SYN-ACK will be retransmitted before an embryonic "
"connection will be aborted.",
           8,  retransmit_threshold, CI_TCP_LISTEN_SYNACK_RETRIES, 0,
           CI_CFG_TCP_SYNACK_RETRANS_MAX, count)

/*****************************************************************/

CI_CFG_OPT("EF_SHARE_WITH", share_with, ci_int32,
"Set this option to allow a stack to be accessed by processes owned by "
"another user.  Set it to the UID of a user that should be permitted to share "
"this stack, or set it to -1 to allow any user to share the stack.  By "
"default stacks are not accessible by users other than root."
"\n"
"Processes invoked by root can access any stack.  Setuid processes can only "
"access stacks created by the effective user, not the real user.  This "
"restriction can be relaxed by setting the onload kernel module option "
"allow_insecure_setuid_sharing=1."
"\n"
"WARNING: A user that is permitted to access a stack is able to: Snoop on any "
"data transmitted or received via the stack; Inject or modify data "
"transmitted or received via the stack; damage the stack and any sockets or "
"connections in it; cause misbehaviour and crashes in any application using "
"the stack.",
           , , 0, -1, SMAX, count)

CI_CFG_OPT("EF_RXQ_SIZE", rxq_size, ci_uint16,
"Set the size of the receive descriptor ring.  Valid values: 512, 1024, 2048 "
"or 4096.\n"

"A larger ring size can absorb larger packet bursts without drops, but may "
"reduce efficiency because the working set size is increased.",
           , , 512, 512, 4096, bincount)

CI_CFG_OPT("EF_TXQ_SIZE", txq_size, ci_uint16,
"Set the size of the transmit descriptor ring.  Valid values: 512, 1024, 2048 "
"or 4096.",
           , , 512, 512, 4096, bincount)

#if CI_CFG_RATE_PACING
CI_CFG_OPT("EF_TX_MIN_IPG_CNTL", tx_min_ipg_cntl, ci_int16,
"Rate pacing value.",  /* FIXME: needs more */
           , ,  0, -1, 20, count)
#endif


CI_CFG_OPT("EF_IRQ_MODERATION", irq_usec, ci_uint32,
"Interrupt moderation interval, in microseconds."
"\n"
"This option only takes effective with EF_PACKET_BUFFER_MODE=1 or 3.  "
"Otherwise the interrupt moderation settings of the kernel net driver "
"take effect.",
           , , 0, 0, 1000000, time:usec)

CI_CFG_OPT("EF_SEND_POLL_THRESH", send_poll_thresh, ci_uint16,
"Poll for network events after sending this many packets."
"\n"
"Setting this to a larger value may improve transmit throughput for small "
"messages by allowing batching.  However, such batching may cause sends to be "
"delayed leading to increased jitter.",
           , , 64, 0, 65535, count)

CI_CFG_OPT("EF_SEND_POLL_MAX_EVS", send_poll_max_events, ci_uint16,
"When polling for network events after sending, this places a limit on the "
"number of events handled.",
           , , 96, 1, 65535, count)

#if CI_CFG_UDP
CI_CFG_OPT("EF_UDP_SEND_UNLOCK_THRESH", udp_send_unlock_thresh, ci_uint16,
"UDP message size below which we attempt to take the stack lock early.  "
"Taking the lock early reduces overhead and latency slightly, but may "
"increase lock contention in multi-threaded applications.",
           , , 1500, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER_MIN", udp_port_handover_min, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER_MAX), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 2, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER_MAX", udp_port_handover_max, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER_MIN), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 1, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER2_MIN", udp_port_handover2_min, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER2_MAX), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 2, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER2_MAX", udp_port_handover2_max, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER2_MIN), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 1, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER3_MIN", udp_port_handover3_min, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER3_MAX), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 2, MIN, MAX, count)

CI_CFG_OPT("EF_UDP_PORT_HANDOVER3_MAX", udp_port_handover3_max, ci_uint16,
"When set (together with EF_UDP_PORT_HANDOVER3_MIN), this causes UDP sockets "
"explicitly bound to a port in the given range to be handed over to the "
"kernel stack.  The range is inclusive.",
           , , 1, MIN, MAX, count)
#endif

CI_CFG_OPT("EF_DELACK_THRESH", delack_thresh, ci_uint16,
"This option controls the delayed acknowledgement algorithm.  A socket may "
"receive up to the specified number of TCP segments without generating an "
"ACK.  Setting this option to 0 disables delayed acknowledgements."
"\n"
"NB. This option is overridden by EF_DYNAMIC_ACK_THRESH, so both options need "
"to be set to 0 to disable delayed acknowledgements.",
           , , 1, 0, 65535, count)
           
#if CI_CFG_DYNAMIC_ACK_RATE
CI_CFG_OPT("EF_DYNAMIC_ACK_THRESH", dynack_thresh, ci_uint16,
"If set to >0 this will turn on dynamic adapation of the ACK rate to "
"increase efficiency by avoiding ACKs when they would reduce "
"throughput.  The value is used as the threshold for number of pending "
"ACKs before an ACK is forced.  If set to zero then the standard "
"delayed-ack algorithm is used.",
           , , 16, 0, 65535, count)
#endif

#if CI_CFG_FD_CACHING
CI_CFG_OPT("EF_SOCKET_CACHE_MAX", sock_cache_max, ci_uint32,
"Sets the maximum number of TCP sockets to cache for this stack.  When "
"set > 0, OpenOnload will cache resources associated with sockets in order "
"to improve connection set-up and tear-down performance.  This improves "
"performance for applications that make new TCP connections at a high rate.",
           , , 0, MIN, MAX, count)

CI_CFG_OPT("EF_PER_SOCKET_CACHE_MAX", per_sock_cache_max, ci_uint32,
"When socket caching is enabled, (i.e. when EF_SOCKET_CACHE_MAX > 0), this "
"sets a further limit on the size of the cache for each socket. If set to "
"zero, no limit is set beyond the global limit specified by "
"EF_SOCKET_CACHE_MAX.",
           , , 0, MIN, MAX, count)
#endif

CI_CFG_OPT("EF_ACCEPTQ_MIN_BACKLOG", acceptq_min_backlog, ci_uint16,
"Sets a minimum value to use for the 'backlog' argument to the listen() "
"call.  If the application requests a smaller value, use this value instead.",
           , , 1, MIN, MAX, count)

CI_CFG_OPT("EF_NONAGLE_INFLIGHT_MAX", nonagle_inflight_max, ci_uint16,
"This option affects the behaviour of TCP sockets with the TCP_NODELAY socket "
"option.  Nagle's algorithm is enabled when the number of packets in-flight "
"(sent but not acknowledged) exceeds the value of this option.  This improves "
"efficiency when sending many small messages, while preserving low latency.\n"

"Set this option to -1 to ensure that Nagle's algorithm never delays sending "
"of TCP messages on sockets with TCP_NODELAY enabled.",
	   , , 50, 1, MAX, count)

CI_CFG_OPT("EF_DEFER_WORK_LIMIT", defer_work_limit, ci_uint16,
"The maximum number of times that work can be deferred to the lock holder "
"before we force the unlocked thread to block and wait for the lock",
           , , 32, MIN, MAX, count)

CI_CFG_OPT("EF_IRQ_CORE", irq_core, ci_int16,
"Specify which CPU core interrupts for this stack should be handled on."
"\n"
"With EF_PACKET_BUFFER_MODE=1 or 3, Onload creates dedicated interrupts for "
"each stack, and the interrupt is assigned to the requested core."
"\n"
"With EF_PACKET_BUFFER_MODE=0 (default) or 2, Onload interrupts are handled "
"via net driver receive channel interrupts.  The sfc_affinity driver is "
"used to choose which net-driver receive channel is used.  It is only "
"possible for interrupts to be handled on the requested core if a net driver "
"interrupt is assigned to the selected core.  Otherwise a nearby core will "
"be selected."
"\n"
"Note that if the IRQ balancer service is enabled it may redirect interrupts "
"to other cores.",
	   , , -1, -1, SMAX, count)

CI_CFG_OPT("EF_IRQ_CHANNEL", irq_channel, ci_int16,
"Set the net-driver receive channel that will be used to handle interrupts "
"for this stack.  The core that receives interrupts for this stack will be "
"whichever core is configured to handle interrupts for the specified net "
"driver receive channel."
"\n"
"This option only takes effect EF_PACKET_BUFFER_MODE=0 (default) or 2.",
	   , , -1, -1, SMAX, count)

CI_CFG_OPT("EF_TXQ_LIMIT", txq_limit, ci_uint32,
"Maximum number of bytes to enqueue on the transmit descriptor ring.",
           , , 0xfffffff, 16 * 1024, 0xfffffff, level)

CI_CFG_OPT("EF_TXQ_RESTART", txq_restart, ci_uint32,
"Level (in bytes) to which the transmit descriptor ring must fall before "
"it will be filled again.",
           , ,    0xfffffff, 1, 0xfffffff, level)

CI_CFG_OPT("EF_RXQ_LIMIT", rxq_limit, ci_int32,
"Maximum fill level for the receive descriptor ring.  This has no effect "
"when it has a value larger than the ring size (EF_RXQ_SIZE).",
           , , 65535, CI_CFG_RX_DESC_BATCH, 65535, level)

CI_CFG_OPT("EF_EVS_PER_POLL", evs_per_poll, ci_uint32,
"Sets the number of hardware network events to handle before performing other "
"work.  The value chosen represents a trade-off: Larger values increase "
"batching (which typically improves efficiency) but may also increase the "
"working set size (which harms cache efficiency).",
           , , 64, 0, 0x7fffffff, level)

#if CI_CFG_PORT_STRIPING
CI_CFG_OPT("EF_STRIPE_NETMASK", stripe_netmask_be32, ci_uint32,
"Port striping is only negotiated with hosts whose IP address is on the same "
"subnet as the local IP, where the subnet mask is defined by this option.",
           , , CI_CFG_STRIPE_DEFAULT_NETMASK, MIN, MAX, ipmask)
#endif

#if CI_CFG_RANDOM_DROP
CI_CFG_OPT("EF_RX_DROP_RATE", rx_drop_rate, ci_uint32,
"Testing use only.  Drop 1 in N packets at random.",
           , ,        0, MIN, MAX, invcount)
#endif

CI_CFG_OPT("EF_SPIN_USEC", spin_usec, ci_uint32,
           "" /* documented in opts_citp_def.h */,
           ,  poll_cycles, 0, MIN, MAX, time:usec)

CI_CFG_OPT("EF_BUZZ_USEC", buzz_usec, ci_uint32,
"Sets the timeout in microseconds for lock buzzing options.  Set to zero to "
"disable lock buzzing (spinning).  Will buzz forever if set to -1.  Also set "
"by the EF_POLL_USEC option.",
           ,  poll_cycles, 0, MIN, MAX, time:usec)

CI_CFG_OPT("EF_HELPER_USEC", timer_usec, ci_uint32,
"Timeout in microseconds for the count-down interrupt timer.  This timer "
"generates an interrupt if network events are not handled by the application "
"within the given time.  It ensures that network events are handled promptly "
"when the application is not invoking the network, or is descheduled."
"\n"
"Set this to 0 to disable the count-down interrupt timer.  It is disabled by "
"default for stacks that are interrupt driven.",
           ,  helper_timer, 500, MIN, MAX, time:usec)

CI_CFG_OPT("EF_HELPER_PRIME_USEC", timer_prime_usec, ci_uint32,
"Sets the frequency with which software should reset the count-down timer.  "
"Usually set to a value that is significantly smaller than EF_HELPER_USEC "
"to prevent the count-down timer from firing unless needed.  Defaults to "
"(EF_HELPER_USEC / 2).",
           ,  helper_timer, 250, MIN, MAX, time:usec)

CI_CFG_OPT("EF_MAX_PACKETS", max_packets, ci_uint32,
"Upper limit on number of packet buffers in each OpenOnload stack.  Packet "
"buffers require hardware resources which may become a limiting factor if "
"many stacks are each using many packet buffers.  This option can be used to "
"limit how much hardware resource and memory a stack uses.  This option "
"has an upper limit determined by the max_packets_per_stack onload "
"module option."
"\n"
"Note: When 'scalable packet buffer mode' is not enabled (see "
"EF_PACKET_BUFFER_MODE) the total number of packet buffers possible in "
"aggregate is limited by a hardware resource.  The SFN5x series adapters "
"support approximately 120,000 packet buffers.",
           , , 32768, 1024, MAX, count)

CI_CFG_OPT("EF_MAX_RX_PACKETS", max_rx_packets, ci_int32,
"The maximum number of packet buffers in a stack that can be used by the "
"receive data path.  This should be set to a value smaller than "
"EF_MAX_PACKETS to ensure that some packet buffers are reserved for the "
"transmit path.",
           , , 24576, 0, 1000000000, count)

CI_CFG_OPT("EF_MAX_TX_PACKETS", max_tx_packets, ci_int32,
"The maximum number of packet buffers in a stack that can be used by the "
"transmit data path.  This should be set to a value smaller than "
"EF_MAX_PACKETS to ensure that some packet buffers are reserved for the "
"receive path.",
           , , 24576, 0, 1000000000, count)

CI_CFG_OPT("EF_RXQ_MIN", rxq_min, ci_uint16,
"Minimum initial fill level for each RX ring.  If Onload is not able to "
"allocate sufficient packet buffers to fill each RX ring to this level, then "
"creation of the stack will fail.",
           , , 256, 2 * CI_CFG_RX_DESC_BATCH + 1, MAX, count)

CI_CFG_OPT("EF_MIN_FREE_PACKETS", min_free_packets, ci_int32,
"Minimum number of free packets to reserve for each stack at initialisation.  "
"If Onload is not able to allocate sufficient packet buffers to fill the "
"RX rings and fill the free pool with the given number of buffers, then "
"creation of the stack will fail.",
           , , 100, 0, 1000000000, count)

CI_CFG_OPT("EF_PREFAULT_PACKETS", prefault_packets, ci_int32,
"When set, this option causes the process to 'touch' the specified number of "
"packet buffers when the Onload stack is created.  This causes memory for "
"the packet buffers to be pre-allocated, and also causes them to be memory-"
"mapped into the process address space.  This can prevent latency jitter "
"caused by allocation and memory-mapping overheads."
"\n"
"The number of packets requested is in addition to the packet buffers that "
"are allocated to fill the RX rings.  There is no guarantee that it will be "
"possible to allocate the number of packet buffers requested."
"\n"
"The default setting causes all packet buffers to be mapped into the "
"user-level address space, but does not cause any extra buffers to be "
"reserved.  Set to 0 to prevent prefaulting.",
           , , 1, 0, 1000000000, count)

/* Max is currently 2^21 EPs.
 * We allocate ep in pages, EP_BUF_PER_PAGE=4 ep per page, so min is 4.
 * 7 synrecv states consume one endpoint, but we also use aux buffers for
 * listening buckets, so the real ratio is 3,5 synrecv state consumes on
 * endpoint. */
CI_CFG_OPT("EF_MAX_ENDPOINTS", max_ep_bufs, ci_uint32,
"This option places an upper limit on the number of accelerated endpoints "
"(sockets, pipes etc.) in an Onload stack.  This option should be set to a "
"power of two between 4 and 2^21."
"\n"
"When this limit is reached listening sockets are not able to accept new "
"connections over accelerated interfaces.  New sockets and pipes created via "
"socket() and pipe() etc. are handed over to the kernel stack and so are not "
"accelerated."
"\n"
"Note: ~4 syn-receive states consume one endpoint, see also "
"EF_TCP_SYNRECV_MAX.",
           , , CI_CFG_NETIF_MAX_ENDPOINTS, 4, CI_CFG_NETIF_MAX_ENDPOINTS_MAX,
           count)

CI_CFG_OPT("EF_TCP_SNDBUF_ESTABLISHED_DEFAULT", tcp_sndbuf_est_def, ci_uint32,
"Overrides the OS default SO_SNDBUF value for TCP sockets in the ESTABLISHED "
"state if the OS default SO_SNDBUF value falls outside bounds set with this "
"option. This value is used when the TCP connection transitions to "
"ESTABLISHED state, to avoid confusion of some applications like netperf.\n"
"The lower bound is set to this value and the upper bound is set to 4 * this "
"value. If the OS default SO_SNDBUF value is less than the lower bound, then "
"the lower bound is used. If the OS default SO_SNDBUF value is more than the "
"upper bound, then the upper bound is used.\n"
"This variable overrides OS default SO_SNDBUF value only, it does not "
"change SO_SNDBUF if the application explicitly sets it "
"(see EF_TCP_SNDBUF variable which overrides application-supplied value).",
           ,  , 128 * 1024, MIN, MAX, bincount)

CI_CFG_OPT("EF_TCP_RCVBUF_ESTABLISHED_DEFAULT", tcp_rcvbuf_est_def, ci_uint32,
"Overrides the OS default SO_RCVBUF value for TCP sockets in the ESTABLISHED "
"state if the OS default SO_RCVBUF value falls outside bounds set with this "
"option. This value is used when the TCP connection transitions to "
"ESTABLISHED state, to avoid confusion of some applications like netperf.\n"
"The lower bound is set to this value and the upper bound is set to 4 * this "
"value. If the OS default SO_RCVBUF value is less than the lower bound, then "
"the lower bound is used. If the OS default SO_RCVBUF value is more than the "
"upper bound, then the upper bound is used.\n"
"This variable overrides OS default SO_RCVBUF value only, it does not "
"change SO_RCVBUF if the application explicitly sets it "
"(see EF_TCP_RCVBUF variable which overrides application-supplied value).",
           ,  , 128 * 1024, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_sndbuf_min, ci_uint32,
"Minimum value for SO_SNDBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_sndbuf, CI_CFG_TCP_SNDBUF_MIN, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_sndbuf_def, ci_uint32,
"Default value for SO_SNDBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_sndbuf,      CI_CFG_TCP_SNDBUF_DEFAULT, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_sndbuf_max, ci_uint32,
"Maximum value for SO_SNDBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_sndbuf,      CI_CFG_TCP_SNDBUF_MAX, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_rcvbuf_min, ci_uint32,
"Minimum value for SO_RCVBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_rcvbuf, CI_CFG_TCP_RCVBUF_MIN, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_rcvbuf_def, ci_uint32,
"Default value for SO_RCVBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_rcvbuf, CI_CFG_TCP_RCVBUF_DEFAULT, MIN, MAX, bincount)

CI_CFG_OPT("", tcp_rcvbuf_max, ci_uint32,
"Maximum value for SO_RCVBUF for TCP sockets.  Set via O/S interface.",
           ,  tcp_rcvbuf,     CI_CFG_TCP_RCVBUF_MAX, MIN, MAX, bincount)

CI_CFG_OPT("", udp_sndbuf_min, ci_uint32,
"Minimum value for SO_SNDBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_sndbuf, CI_CFG_UDP_SNDBUF_MIN, MIN, MAX, bincount)

CI_CFG_OPT("", udp_sndbuf_def, ci_uint32,
"Default value for SO_SNDBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_sndbuf, CI_CFG_UDP_SNDBUF_DEFAULT, MIN, MAX, bincount)

CI_CFG_OPT("", udp_sndbuf_max, ci_uint32,
"Maximum value for SO_SNDBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_sndbuf, CI_CFG_UDP_SNDBUF_MAX, MIN, MAX, bincount)

CI_CFG_OPT("", udp_rcvbuf_min, ci_uint32,
"Minimum value for SO_RCVBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_rcvbuf, CI_CFG_UDP_RCVBUF_MIN, MIN, MAX, bincount)

CI_CFG_OPT("", udp_rcvbuf_def, ci_uint32,
"Default value for SO_RCVBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_rcvbuf, CI_CFG_UDP_RCVBUF_DEFAULT, MIN, MAX, bincount)

CI_CFG_OPT("", udp_rcvbuf_max, ci_uint32,
"Maximum value for SO_RCVBUF for UDP sockets.  Set via O/S interface.",
           ,  udp_rcvbuf, CI_CFG_UDP_RCVBUF_MAX, MIN, MAX, bincount)

CI_CFG_OPT("EF_TCP_SNDBUF", tcp_sndbuf_user, ci_uint32,
"Override SO_SNDBUF for TCP sockets (Note: the actual size of the buffer is "
"double the amount requested, mimicking the behavior of the Linux kernel.)",
           ,  tcp_sndbuf,     0, MIN, MAX, bincount)

CI_CFG_OPT("EF_TCP_RCVBUF", tcp_rcvbuf_user, ci_uint32,
"Override SO_RCVBUF for TCP sockets. (Note: the actual size of the buffer is "
"double the amount requested, mimicking the behavior of the Linux kernel.)",
           ,  tcp_rcvbuf, 0, MIN, MAX, bincount)

CI_CFG_OPT("EF_UDP_SNDBUF", udp_sndbuf_user, ci_uint32,
"Override SO_SNDBUF for UDP sockets. (Note: the actual size of the buffer is "
"double the amount requested, mimicking the behavior of the Linux kernel.)",
           ,  udp_sndbuf, 0, MIN, MAX, bincount)

CI_CFG_OPT("EF_UDP_RCVBUF", udp_rcvbuf_user, ci_uint32,
"Override SO_RCVBUF for UDP sockets. (Note: the actual size of the buffer is "
"double the amount requested, mimicking the behavior of the Linux kernel.)",
           ,  udp_rcvbuf, 0, MIN, MAX, bincount)

CI_CFG_OPT("EF_TCP_BACKLOG_MAX", tcp_backlog_max, ci_uint32,
"Places an upper limit on the number of embryonic (half-open) connections for "
"one listening socket; see also EF_TCP_SYNRECV_MAX.  This value is overridden "
"by /proc/sys/net/ipv4/tcp_max_syn_backlog.",
           , , CI_TCP_LISTENQ_MAX, MIN, MAX, bincount)

/* The number we really use is tcp_synrecv_max*2 - it is the maximum
 * number of aux buffers, assuming that synrrecv state can use one half of
 * them and listening bucktes use another half. */
CI_CFG_OPT("EF_TCP_SYNRECV_MAX", tcp_synrecv_max, ci_uint32,
"Places an upper limit on the number of embryonic (half-open) connections in "
"an Onload stack; see also EF_TCP_BACKLOG_MAX.  By default, "
"EF_TCP_SYNRECV_MAX = 4 * EF_TCP_BACKLOG_MAX.",
           , , CI_TCP_LISTENQ_MAX * CI_CFG_ASSUME_LISTEN_SOCKS,
           MIN, CI_CFG_NETIF_MAX_ENDPOINTS_MAX, bincount)

CI_CFG_OPT("EF_TCP_INITIAL_CWND", initial_cwnd, ci_int32,
"Sets the initial size of the congestion window (in bytes) for TCP "
"connections. Some care is needed as, for example, setting smaller than the "
"segment size may result in Onload being unable to send traffic. "
"\n"
"WARNING: Modifying this option may violate the TCP protocol.",
           ,  , 0, 0, SMAX, count)

CI_CFG_OPT("EF_TCP_LOSS_MIN_CWND", loss_min_cwnd, ci_int32,
"Sets the minimum size of the congestion window for TCP connections following "
"loss."
"\n"
"WARNING: Modifying this option may violate the TCP protocol.",
           ,  , 0, 0, SMAX, count)

#if CI_CFG_TCP_FASTSTART
CI_CFG_OPT("EF_TCP_FASTSTART_INIT", tcp_faststart_init, ci_uint32,
"The FASTSTART feature prevents Onload from delaying ACKs during times when "
"doing so may reduce performance.  FASTSTART is enabled when a connection is "
"new, following loss and after the connection has been idle for a while."
"\n"
"This option sets the number of bytes that must be ACKed by the receiver "
"before the connection exits FASTSTART.  Set to zero to disable FASTSTART "
"on new connections.",
           ,  , 64*1024, 0, MAX, count)

CI_CFG_OPT("EF_TCP_FASTSTART_IDLE", tcp_faststart_idle, ci_uint32,
"The FASTSTART feature prevents Onload from delaying ACKs during times when "
"doing so may reduce performance.  FASTSTART is enabled when a connection is "
"new, following loss and after the connection has been idle for a while."
"\n"
"This option sets the number of bytes that must be ACKed by the receiver "
"before the connection exits FASTSTART.  Set to zero to prevent a connection "
"entering FASTSTART after an idle period.",
           ,  , 64*1024, 0, MAX, count)

CI_CFG_OPT("EF_TCP_FASTSTART_LOSS", tcp_faststart_loss, ci_uint32,
"The FASTSTART feature prevents Onload from delaying ACKs during times when "
"doing so may reduce performance.  FASTSTART is enabled when a connection is "
"new, following loss and after the connection has been idle for a while."
"\n"
"This option sets the number of bytes that must be ACKed by the receiver "
"before the connection exits FASTSTART following loss.  Set to zero to "
"disable FASTSTART after loss.",
           ,  , 64*1024, 0, MAX, count)
#endif

CI_CFG_OPT("EF_RFC_RTO_INITIAL", rto_initial, ci_iptime_t,
"Initial retransmit timeout in milliseconds.  i.e. The number of "
"milliseconds to wait for an ACK before retransmitting packets.",
           ,  rto, CI_TCP_TCONST_RTO_INITIAL, MIN, MAX, time:msec)

CI_CFG_OPT("EF_RFC_RTO_MIN", rto_min, ci_iptime_t,
"Minimum retransmit timeout in milliseconds.",
           ,  rto, CI_TCP_TCONST_RTO_MIN, MIN, MAX, time:msec)

CI_CFG_OPT("EF_RFC_RTO_MAX", rto_max, ci_iptime_t,
"Maximum retransmit timeout in milliseconds.",
           ,  rto, CI_TCP_TCONST_RTO_MAX, MIN, MAX, time:msec)

CI_CFG_OPT("EF_KEEPALIVE_TIME", keepalive_time, ci_iptime_t,
"Default idle time before keepalive probes are sent, in milliseconds.",
           , , CI_TCP_TCONST_KEEPALIVE_TIME, MIN, MAX, time:msec)

CI_CFG_OPT("EF_KEEPALIVE_INTVL", keepalive_intvl, ci_iptime_t,
"Default interval between keepalives, in milliseconds.",
           , ,  CI_TCP_TCONST_KEEPALIVE_INTVL, MIN, MAX, time:msec)

CI_CFG_OPT("EF_KEEPALIVE_PROBES", keepalive_probes, ci_uint32,
"Default number of keepalive probes to try before aborting the connection.",
           , , CI_TCP_KEEPALIVE_PROBES, MIN, MAX, count)

#ifndef NDEBUG
CI_CFG_OPT("EF_TCP_MAX_SEQERR_MSGS", tcp_max_seqerr_msg, ci_uint32,
"Maximum number of unacceptable sequence error messages to emit, per socket.",
           , , -1, MIN, MAX, count)
#endif

#if CI_CFG_BURST_CONTROL
CI_CFG_OPT("EF_BURST_CONTROL_LIMIT", burst_control_limit, ci_uint32,
"If non-zero, limits how many bytes of data are transmitted in a single burst. "
"This can be useful to avoid drops on low-end switches which contain limited "
"buffering or limited internal bandwidth.  This is not usually needed for use "
"with most modern, high-performance switches.",
           , , CI_CFG_TCP_BURST_CONTROL_LIMIT, MIN, MAX, count)
#endif

#if CI_CFG_CONG_AVOID_NOTIFIED
CI_CFG_OPT("EF_CONG_NOTIFY_THRESH", cong_notify_thresh, ci_uint32,
/* FIXME: need to introduce concept of burst control. */
"How much tx queue used before we activate burst control.",
           , , CI_CFG_CONG_NOTIFY_THRESH, MIN, MAX, bincount)
#endif

#if CI_CFG_CONG_AVOID_SCALE_BACK
CI_CFG_OPT("EF_CONG_AVOID_SCALE_BACK", cong_avoid_scale_back, ci_uint32,
"When >0, this option slows down the rate at which the TCP congestion window "
"is opened.  This can help to reduce loss in environments where there is lots "
"of congestion and loss.",
           , , 0, MIN, MAX, count/*?*/)
#endif

CI_CFG_OPT("EF_FREE_PACKETS_LOW_WATERMARK", free_packets_low, ci_uint16,
"Keep free packets number to be at least this value.  EF_MIN_FREE_PACKETS "
"defines initialisation behaviour; this value is about normal application "
"runtime.  In some combinations of hardware and software, Onload is not "
"able allocate packets at any context, so it makes sense to keep some "
"spare packets.  Default value 0 is interpreted as EF_RXQ_SIZE/2",
           , , 0, MIN, MAX, count)

#if CI_CFG_PIO
CI_CFG_OPT("EF_PIO_THRESHOLD", pio_thresh, ci_uint16,
"Sets a threshold for the size of packet that will use PIO, if turned on "
"using EF_PIO.  Packets up to the threshold will use PIO.  Larger packets "
"will not.",
           , , 1514, 0, MAX, count)
#endif

CI_CFG_OPT("EF_TX_PUSH_THRESHOLD", tx_push_thresh, ci_uint16,
"Sets a threshold for the number of outstanding sends before we stop using "
"TX descriptor push.  This has no effect if EF_TX_PUSH=0.  This "
"threshold is ignored, and assumed to be 1, on pre-SFN7000-series "
"hardware. It makes sense to set this value similar to EF_SEND_POLL_THRESH",
           , , 100, 1, MAX, count)

#ifdef ONLOAD_OFE
CI_CFG_OPT("EF_OFE_ENGINE_SIZE", ofe_size, ci_uint32,
"Size (in bytes) of Onload Filter Engine to be allocated "
"when a new stack is created.",
           , , 0, 0, MAX, bincount)
#endif

#define CI_EF_LOG_DEFAULT ((1 << EF_LOG_BANNER) | (1 << EF_LOG_RESOURCE_WARNINGS) | (1 << EF_LOG_CONFIG_WARNINGS) | (1 << EF_LOG_USAGE_WARNINGS))
CI_CFG_OPT("EF_LOG", log_category, ci_uint32,
"Designed to control how chatty Onload's informative/warning messages are.  "
"Specified as a comma seperated list of options to enable and disable "
"(with a minus sign).  Valid options are 'banner' (on by default), "
"'resource_warnings' (on by default), 'config_warnings' (on by default) "
"'conn_drop' (off by default) and 'usage_warnings' (on by default).  E.g.: "
"To enable conn_drop: EF_LOG=conn_drop.  " "E.g.: To enable conn_drop and "
"turn off resource warnings: EF_LOG=conn_drop,-resource_warnings",
           , , CI_EF_LOG_DEFAULT, 0, MAX, count)

#if CI_CFG_SEPARATE_UDP_RXQ
CI_CFG_OPT("EF_SEPARATE_UDP_RXQ", separate_udp_rxq, ci_uint32,
"Use separate RXQ for udp RX.",
           1, , 0, 0, 1, yesno)
#endif

CI_CFG_OPT("EF_SCALABLE_FILTERS", scalable_filter_ifindex, ci_int32,
"Specifies the interface on which to enable support for scalable filters, "
"and configures the scalable filter mode(s) to use.  Scalable filters "
"allow Onload to use a single hardware MAC-address filter to avoid "
"hardware limitations and overheads.  This removes restrictions on "
"the number of simultaneous connections and increases performance of "
"active connect calls, but kernel support on the selected interface is "
"limited to ARP/DHCP/ICMP protocols and some Onload features that rely "
"on unaccelerated traffic (such as receiving fragmented UDP datagrams) "
" will not work.  Please see the Onload user guide for full details.\n"
"\n"
"Depending on the mode selected this option will enable support for:\n"
" - scalable listening sockets;\n"
" - IP_TRANSPARENT socket option;\n"
"\n"
"The interface specified must be a SFN7000 or later NIC."
"\n"
"Format of EF_SCALABLE_FILTERS variable is as follows:\n"
"  EF_SCALABLE_FILTERS=<interface-name>[=mode[:mode]]\n"
"      where mode is one of: transparent_active,passive,rss\n"
"The following modes and their combinations can be specified:\n"
"  transparent_active, passive, rss:transparent_active, "
"transparent_active:passive",
           ,  , 0, 0, SMAX, count)

#define CITP_SCALABLE_MODE_NONE              0x0
#define CITP_SCALABLE_MODE_RSS               0x1
#define CITP_SCALABLE_MODE_TPROXY_ACTIVE     0x2
#define CITP_SCALABLE_MODE_PASSIVE           0x4

#define CITP_SCALABLE_MODE_TPROXY_ACTIVE_RSS (CITP_SCALABLE_MODE_TPROXY_ACTIVE | \
                                              CITP_SCALABLE_MODE_RSS)

CI_CFG_OPT("EF_SCALABLE_FILTERS_MODE", scalable_filter_mode, ci_int32,
           "Stores scalable filter mode set with EF_SCALABLE_FILTERS.  "
           "To be set indirectly with EF_SCALABLE_FILTERS variable",
           ,  , -1, -1, 6, oneof:
           auto;
           none;reserved1;transparent_active;rss_transparent_active;
           passive;reserved5;passive_tproxy_active;
           )

#define CITP_SCALABLE_FILTERS_DISABLE 0
#define CITP_SCALABLE_FILTERS_ENABLE  1
CI_CFG_OPT("EF_SCALABLE_FILTERS_ENABLE", scalable_filter_enable, ci_int32,
"Turn the scalable filter feature on or off on a stack.  If this is set to 1 "
"then the configuration selected in EF_SCALABLE_FILTERS will be used.  If this "
"is set to 0 then scalable filters will not be used for this stack.  If unset "
"this will default to 1 if EF_SCALABLE_FILTERS is configured.",
           , , 0, 0, 1, yesno)

#ifdef CI_CFG_OPTGROUP
/* define some categories - currently more as an example than as the final
   thing */
CI_CFG_OPTGROUP(stripe_netmask_be32,         stripeing, 100)
CI_CFG_OPTGROUP(stripe_dupack_threshold,     stripeing, 100)
CI_CFG_OPTGROUP(stripe_tcp_opt,              stripeing, 100)

CI_CFG_OPTGROUP(keepalive_time,              keepalive, 100)
CI_CFG_OPTGROUP(keepalive_intvl,             keepalive, 100)
CI_CFG_OPTGROUP(keepalive_probes,            keepalive, 100)

CI_CFG_OPTGROUP(retransmit_threshold,        tcp_retransmission, 100)
CI_CFG_OPTGROUP(rto,                         tcp_retransmission, 100)
#endif


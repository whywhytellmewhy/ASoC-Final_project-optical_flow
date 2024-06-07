# This file is automatically generated by Catapult each time CDesignChecker is
# is launched from Catapult. Any user-applied edits will be overwritten.

set ::env(SLEC_GCC_HOME) /usr/cadtool/mentor/Catapult/2023.1/Mgc_home
# Property checks

# add Verification Mode settings
set_verification_mode -c_property_checks 

# Clear all settings
config_property_checks -disable -all
# Enable rules
config_property_checks -enable -abr
config_property_checks -enable -abw
config_property_checks -enable -acc
config_property_checks -enable -acs
config_property_checks -enable -aic
config_property_checks -enable -als
config_property_checks -enable -aob
config_property_checks -enable -apt
config_property_checks -enable -awe
config_property_checks -enable -cas
config_property_checks -enable -cbu
config_property_checks -enable -ccc
config_property_checks -enable -cgr
config_property_checks -enable -cia
config_property_checks -enable -cmc
config_property_checks -enable -cns
config_property_checks -enable -cwb
config_property_checks -enable -dbz
config_property_checks -enable -diu
config_property_checks -enable -fvi
config_property_checks -enable -fxd
config_property_checks -enable -ise
config_property_checks -enable -lrc
config_property_checks -enable -mdb
config_property_checks -enable -mxs
config_property_checks -enable -nco
config_property_checks -enable -osa
config_property_checks -enable -ovl
config_property_checks -enable -pdd
config_property_checks -enable -riu
config_property_checks -enable -rrt
config_property_checks -enable -sat
config_property_checks -enable -stf
config_property_checks -enable -sud
config_property_checks -enable -umr

# Symbolic Memory Control
set_global symbolic_memory_threshold_size 256

# verification effort
set_verification_effort -medium
set_global report_undecided_solver_properties 1



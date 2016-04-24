budgy<-cbind(
batteries<-c(bweight<-140*2,bcost<-34.90*2),     #two batteries at 140g cost $39.90 each

gps<-c(gweightest<-1,gcost<-49.99),

promicro<-c(mweightest<-1,mcost<-19.95),

altimeter<-c(altw<-1,altc<-9.95),

motors<-c(motweight<-0,motcost<-0),

camera<-c(camweightest<-1,camcost<-39.95),

accel<-c(acweightest<-1,accost<-17.50))







wt_cst<-data.frame(rowSums(budgy))
row.names(wt_cst)<-c("Total Weight","Total Cost")
wt_cst


#================Thrust calc===================================

#Hey, I have a hacker style brushless outrunner which has a rating of 924Kv and i have a 10x4.7 propeller. I need to calculate an estimate of the thrust. I came across this equation for the static thrust,

#$T = [ (eta*P)^2 * 2 * \pi *R^2 * \rho ]^{0.3333}$
  
 # T = thrust (in Newtons)
#eta = prop hover efficiency = 0.7-0.8 is typical for unstalled low-pitch props
#P = shaft power = voltage * current * motor efficiency (in Watts)
#$\pi = 3.14159$
 # R = prop radius (in meters)
#$\rho = air density = 1.22 kg/m^3$
  
 # In this equation i'm not sure what to use for eta (i was thinking 0.75). I also don't know what I should use for current, voltage, motor efficiency and propeller radius. Should i just use the max current and voltage that the motor can take which is 17A and 11V respectively. Should I just assume the motor is around 75\% efficient? Will the prop radius just be half the length of the propeller, in my case that will be 5 in (0.127 m).

#If i use the values i assumed above i get,

#$T = [(0.75*11*17*0.75)^2 * 2 * \pi * 0.127 *0.127 * 1.22]^{0.3333} (0.127 is the radius in m)$
 # $T ~= 11.1 N$
  
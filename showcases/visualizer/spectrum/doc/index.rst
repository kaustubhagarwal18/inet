:orphan:

Visualizing the Spectrum of Radio Signals
=========================================

Goals
-----

.. INET can visualize the spectrum of signals in various ways. This is useful
   for troubleshooting, and to better understand what is happening in terms of
   interference. -> visualize the signal power in various frequencies

INET has support for visualizing the spectrum of radio signals present in a simulation.
The spectral visualization helps with troubleshooting simulation models, and understanding
interference in the network.

This showcase demonstrates the available spectrum visualization features with example
simulations.

| INET version: ``4.2``
| Source files location: `inet/showcases/visualizer/spectrum <https://github.com/inet-framework/inet-showcases/tree/master/visualizer/spectrum>`__

About the Visualizer
--------------------

**V1** The :ned:`RadioMediumVisualizer` can visualize spectrums in the following ways:

**V2** The :ned:`RadioMediumVisualizer` can visualize spectrums, in addition to the visualization of
propagating signals and other stuff that the radio medium activity showcase is about. The module
can visualize spectrums in the following ways:

.. - can visualize spectral stuff
   - there are three features for that
   - spectrum figure: display the spectrum of signals, including noise, at nodes (and probes) currently
   - spectrogram: display the spectrum of signals as a spectrogram; i.e. how the spectrum changes
  what was it like in the past and what its going to be like in the future
   - power density map: display the power density at all points in the scene, at a certain frequency,
  with colors

- **Spectrum figure:** The figure can display the signal power as a function of frequency at a given point in space, i.e. at network nodes, at the current time. When the spectrum is displayed at the transmitting and receiving nodes, the transmitted/received signal and other signals (and noises) are displayed separately.
- **Spectrogram:** The spectrogram displays the signal power as a function of frequency at a given point in space, and displays how the spectrum changed in time (and how it will change in time) **TODO** more on that. It uses color coding for the signal power.
- **Power Density Map:** The power density map displays the signal power as a heatmap on the scene at the current time, at a given frequency. The resolution can be adjusted for more/less detail. Also, it can display the heatmap only in the vicinity of network nodes. High computing capacity needed.

.. Note that the spectrums are only represented and can be visualized when using the dimensional analog model.

.. note:: The spectrums are only represented and can be visualized when using the dimensional analog model.

.. note:: The spectrums can only be represented and visualized when using the dimensional analog model.

.. note:: The spectrums are only represented and can only be visualized when using the dimensional analog model.

.. note:: The spectrums are represented and can be visualized only when using the dimensional analog model.

structure:

- goals -> inet can do the spectral visualization stuff
- about the visualizer -> these are the features of the medium visualizer as well -> the three stuff
- the probe -> this can check signal power and spectrum everywhere and its draggable in real time so its useful

The Probe Module
================

The :ned:`Probe` module is technically a network node that contains only an antenna submodule,
and a mobility submodule.
It can detect the signal power present at its location, which can be displayed using the visualizer.
The probe can be dragged with the mouse as the simulation is running to examine the signals present
at any point in the network. This is useful for troubleshooting and understanding the situation.

**TODO** the other way around (what it can do, then what is it -> also what the submodules do)

**TODO** shift-left click

**TODO** total power

.. figure:: media/probe.png
   :align: center

Spectrum Figure
---------------

  - the settings common to all three features -> the scale of the three axes; used when appropriate
  - the spectrum figure in detail (how the axes change; the color coding; the units)
  - mode and interpolation size; the other parameters just mention
  - the config
  - results

**V1** The spectrum figure displays the signal power density over frequency at the current time, at a given position (such as a network node or probe). The visualization is enabled with the visualizer's :par:`displaySpectrums` parameter.

**V2** The spectrum figure displays the signal power density over frequency at the current time, at a given position (such as a network node or probe). The power axis is logarithmic, and the power density is displayed in units of `dBmWpMHz`, i.e. dBmW/MHz.
The visualization is enabled with the visualizer's :par:`displaySpectrums` parameter.

.. **TODO** colors

.. **V1** The spectrum plots are color coded. By default, the spectrum figure displays the total power density at given location (blue curve),
   except for the transmitting and receiveing nodes, where the transmitted/received signal (green curve) is displayed
   separately from other signals/noises (red curve).

The spectrum plots are color coded. By default, the total power density is shown at the given position (blue curve),
except for the transmitting and receiveing nodes, where the transmitted/received signal (green curve) is displayed
separately from other signals/noises (red curve).

**TODO** image

.. .. figure:: media/signal.png

.. |signal| image:: media/signal3.png

.. |total| image:: media/total.png

+---------+----------+
| |total| | |signal| |
+---------+----------+

**TODO** it should be on the same scale; it should be a receiver

The visualizers :par:`spectrumMode` parameter specifies what to display in the spectrum figures,
one of the following:

- ``total``: display the total power density in the transmission medium at that location (visualizes signals at every node)
- ``signal``: display the power density of the transmitted or received signal (only visualizes signals at the transmitter and receiver nodes) -> **TODO** displays the noise/interfering signals as well
- ``auto`` (default): display the transmitted or received signal if there is any, otherwise display the total power density (visualizes signals at every node)

All spectrum figures, spectrograms and power density maps in the network use the same scale
in power, frequency and time, so the visualizations can be compared. The scale is automatic
by default, and it's determined by the bandwidth, center frequency and power of signals present in the network. The scale can extend over time as new signals occur in the network, but doesn't contract.

.. The scales of the axes can be specified manually. There are a set of parameters which are shared by spectrum figures, spectrograms, and power density maps, and set
   the scale of the power, frequency and time axes. Even though non of the three visualizations make use of all three axes, the settings are global **TODO**.
   There are parameters of the three axes, for auto axes configuration (e.g. :par:`AutoPowerAxis`; true by default), and setting the min and max values of an axis manually (e.g. :par:`signalMinPowerDensity`, :par:`signalMaxPowerDensity`).
   For the complete list of shared parameters, see the NED documentation of :ned:`MediumVisualizerBase`.

The scales of the power, frequency and time axes can be specified manually by a set of parameters which are shared by spectrum figures, spectrograms, and power density maps. Even though non of the three visualizations make use of all three axes, the settings are global **TODO**.
There are parameters for the three axes, for auto axes configuration (e.g. :par:`AutoPowerAxis`; true by default), and setting the min and max values of an axis manually (e.g. :par:`signalMinPowerDensity`, :par:`signalMaxPowerDensity`).
For the complete list of shared parameters, see the NED documentation of :ned:`MediumVisualizerBase`.

.. The power and frequency axes of the figure are

**TODO** image

..   - all figures share the same scale
  - which is automatic by default, determined by the bandwidth, center frequency and power of signals present in the network. Note that the scale can extend over time as new signals occur in the network, but it can only extend
  - the scale can be specified manually
  - there are a set of parameters which pertain to all three visualization features, and set the scale of the power, frequency and time axes.
  - even though not all three features make use of all three axes, the settings are global
  - the parameters

.. **TODO** the mode parameter

.. **TODO** enable

**TODO** the default unit dBmWpMHz

.. **TODO** can only visualize power density -> when there is a frequency axis, its obvious;

In the example simulation demonstrating the spectrum figure, two pairs of hosts communicate with each other on different, but adjacent Wifi channels. The simulation uses the following network:

**TODO** network image

.. figure:: media/network.png
   :width: 100%
   :align: center

In the simulation, ``host1`` sends UDP packets to ``host2``, and ``host3`` to ``host4``. Here is the configuration in omnetpp.ini:

.. literalinclude:: ../omnetpp.ini
   :start-at: Config SpectrumFigure
   :end-before: Config Spectrogram
   :language: ini

The ``General`` configuration contains keys pertaining to all simulations, configuring background noise:

.. literalinclude:: ../omnetpp.ini
   :start-at: backgroundNoise.typename
   :end-at: backgroundNoise.powerSpectralDensity
   :language: ini

Setting the radio type to dimensional:

.. literalinclude:: ../omnetpp.ini
   :start-at: radio.typename
   :end-at: transmitter.frequencyGains
   :language: ini

And configuring the Wifi channels:

.. literalinclude:: ../omnetpp.ini
   :start-at: channelNumber = 0
   :end-at: channelNumber = 3
   :language: ini

Spectrogram
-----------

The spectrogram displays the signal power density over frequency, and how it changed/will change in time, at a give position.

The spectrogram displays the signal power density over frequency and time, at a given position.
The signal power density is color coded as a heatmap...more intensive colors meaning higher power density...it uses the same color coding as the spectrum figure...that is blue for total power density, green for transmitted/received signal and red for interfering signals and noise.
It shows how the power density was in the past and how it will in the future...**TODO**

The visualization is enabled with the visualizer's :par:`displaySpectrograms` parameter.
Similarly to the spectrum figure, the :par:`spectrogramMode` parameter can specify what to display,
``total``, ``signal`` or ``auto``...

The scale is the global scale...

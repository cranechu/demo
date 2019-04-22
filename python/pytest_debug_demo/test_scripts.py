import pytest
import logging

@pytest.mark.parametrize("qcount", [1, 2, 4, 8, 15])
def test_ioworker_iops_multiple_queue(qcount):
    logging.info(qcount)


def test_ioworker_iops_single():
    logging.info("single")